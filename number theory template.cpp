/////////   https://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

#define print(a)        for (auto x : a) cout << x << " "; cout << endl
#define print_upto(a,n)        for(int i=0;i<n;i++)    cout<<a[i]<<" "; cout<<endl
#define take(x,n)           for(int i=0;i<n;i++)  cin>>x[i];

#define rep(i,n)        for(int i=0;i<n;i++)
#define repange(i,a,b)      for(int i=a;i<=b;i++)
#define reprange(i,a,b)     for(int i=a;i>=b;i--)

void fast();
int mul(int a, int b);
void sieve();
void extended(int a,int b);


#define ll long long
#define ull unsigned long long
#define ldob long double
#define dob double
#define F first
#define S second
#define pii pair<int, int>
#define vec(a) vector<a>
#define umap(a, b) unordered_map<a, b>
#define endl "\n"
#define MOD 1000000007
#define pb push_back
#define mp make_pair


//======================================================================================//

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;  
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ", "; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << " "; return os; }
template <class T> ostream& operator << (ostream &os, const multiset<T> &v) { for (T i : v) os << i << " "; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.F << ' ' << v.S; return os; }
template <class T, class S> ostream& operator << (ostream &os, const map<T, S> &v) { for (auto i : v) os << '(' << i.F << " => " << i.S << ')' << ' '; return os; } 
 

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <class Arg1, class... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* sep = strchr(names + 1, ',');
        cerr.write(names, sep - names) << " : " << arg1 << "  ";
        __f(sep + 1, args...);
    }
#else
#define trace(...) 0
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#endif // ifndef ONLINE_JUDGE

clock_t time_p=clock();
void TTIIMMEE()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
}; // datatype ki jagah gp_hash_table<key_type,int,chash> , for eg : Dp like hashmap : vector<gp_hash_table<int,int,chash>>dp(N);

//======================================================================================//
                
ll modexp(ll x, ll n,ll mod){
    if(n==0)return 1;
    else if(n&1){return (modexp((x*x)%mod, n/2,mod)%mod * x%mod)%mod;}
    else{return (modexp((x*x)%mod, n/2,mod)%mod);}
}
  
// Returns n^(-1) mod p 
int modInverse(int n, int p) { return modexp(n, p-2, p); } 



#define int long long int
#define N 200005
int ar[N];
int prime[N];
int n,a,b,mod;
vec(int) allprime;
vec(int) v;

inline int add(int a,int b) {  return (a%mod + b%mod + mod)%mod; }
inline int mul(int a,int b) {  return (a%mod * b%mod + mod)%mod; }
inline int sub(int a,int b) {  return (a%mod - b%mod + mod)%mod; }



int32_t main()
{
    fast();

    int testcase=1;    //change t if required
    //cin>>testcase;
    while(testcase--)
    {
        
        sieve();
        

    }
    TTIIMMEE();
    return 0;
}



//functions


int M = 1000005; 
void sieve()
{
    for(int i = 2; i < M; i++)
    {
        if(!prime[i])
        {
            allprime.pb(i);
            for(int j = 1; i * j < M; j++)
                prime[i * j] = i;
        }
    }
}


int x,y,GCD;
void extended(int a,int b)
{   
    if(b==0)
    {

        x=1;
        y=0;
        GCD=a;
        return ;
    }
    extended(b,a%b);
    int cx,cy;
    cx = y;
    cy=x-(a/b)*y;

    x=cx;
    y=cy;
    return;
}

void fast()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
