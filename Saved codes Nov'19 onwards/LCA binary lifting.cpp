// LCA
//Binary lifting

#include <bits/stdc++.h>
using namespace std;
    
#define F first
#define S second
#define endl "\n"
#define pb push_back
    
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
    
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ", "; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << " "; return os; }
template <class T> ostream& operator << (ostream &os, const multiset<T> &v) { for (T i : v) os << i << " "; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.F << ' ' << v.S; return os; }
template <class T, class S> ostream& operator << (ostream &os, const map<T, S> &v) { for (auto i : v) os << '(' << i.F << " => " << i.S << ')' << ' '; return os; } 
    
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 1e5 + 5;
vector<vector<int>> v(N);
vector<int> par(N), level(N), mx(N, 0);
vector<vector<int>> dp(log2(N)+5, vector<int>(N));
int n;
 
void dfs_lca(int a, int par, int lev)
{
    ::par[a] = par;
    level[a] = lev;
    for(int i:v[a])
    {
        if(i == par) continue;
        dfs_lca(i, a, lev+1);
    }
}   
 
void find_ancestor()
{
    for(int i=1;i<=n;i++)
    {
        dp[0][i] = par[i];
    }
 
    for(int i=1;i<dp.size();i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}
 
ll lca(int a, int b)
{
    if(level[b] < level[a]) swap(a, b);
    
    int diff = level[b]-level[a];
    while(diff)
    {
        int log = log2(diff);
        b = dp[log][b];
        diff -= (1<<log);
    }
    while(a != b)
    {
        int i = log2(level[a]);
        while(i>0 && dp[i][a] == dp[i][b]) i--;
 
        a = dp[i][a];
        b = dp[i][b];
    }
    // return val; // if return max edge
    return a; // return ancestor
}
 
void compute_lca()
{
    dfs_lca(1, 0, 0);
    find_ancestor();
}
 
int dis(int a, int b)
{
    return level[a] + level[b] - level[lca(a, b)] * 2;
}
 
void solve()
{
    compute_lca();
    int q; cin>>q;
    while(q--)
    {
        int x, y, a, b, k; cin>>x>>y>>a>>b>>k;
        if(level[a] < level[b]) swap(a, b);
 
        int xy = dis(x, y);
 
        int t = dis(a, b);
        int t1 = dis(a, x) + dis(b, y) + 1;
        int t4 = dis(a, y) + dis(b, x) + 1;
 
        if(t <= k && (k - t) % 2 == 0)
        {
            cout<<"YES\n";
            continue;
        }
        if(t1 <= k && (k - t1) % 2 == 0)
        {
            cout<<"YES\n";
            continue;
        }
        if(t4 <= k && (k - t4) % 2 == 0)
        {
            cout<<"YES\n";
            continue;
        }
 
        cout<<"NO\n";
    }   
}
 
int main()
{
    fast();
    cin>>n;
    for(int i = 1; i < n; i++)
    {
        int a, b; cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    solve();
}