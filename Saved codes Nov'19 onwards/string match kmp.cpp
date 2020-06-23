#include <bits/stdc++.h>
using namespace std;

#define print(a)        for (auto x : a) cout << x << " "; cout << endl
#define print_upto(a,n)        for(int i=0;i<n;i++)    cout<<a[i]<<" "; cout<<endl
#define take(x,n)           for(int i=0;i<n;i++)  cin>>x[i];
#define rep(i,n)        for(int i=0;i<n;i++)
#define repange(i,a,b)      for(int i=a;i<=b;i++)
#define reprange(i,a,b)     for(int i=a;i>=b;i--)

void fast();

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
#define inf 1e18
#define pb push_back
#define mp make_pair
#define int long long int
#define N 100001
int reset[N];
int n,a,b,c,k,q,mod;
vec(int) v;
//////////////////////////////////////////////////

char str[1100000];
char substr[1100000];
int b[1100000];

void kmpPreprocess(char *substr)
{
    const int m = strlen(substr);
    int i = 0, j = -1;

    b[i] = -1;
    while(i < m)
    {
        while(j >= 0 && substr[i] != substr[j])
            j = b[j];

        i++;
        j++;
        b[i] = j;
    }
}

int kmp(char *str, char *substr)
{
    int i=0, j=0, count = 0;
    const int n = strlen(str);
    const int m = strlen(substr);

    kmpPreprocess(substr);
    while (i<n)
    {
        while (j>=0 && str[i]!=substr[j])
            j=b[j];

        i++;
        j++;

        if (j==m)
        {
            count++;
            j=b[j];
        }
    }
    return count;
}



///////////////////////////////////////////////////
void kmp_pre(string pat)
{
    int i=0;
    int j=1;
    reset[0]=-1;
    while(i<pat.length())
    {
        while(j>=0 && pat[i]!=pat[j])   j=reset[j];

        i++;j++;
        reset[i]=j;
    }
}

void kmpSearch(string str,string pat)
{
    kmp_pre(pat);

    int i=0;int j=0;
    while(i<str.size())
    {
        while(j>=0 && str[i]!=pat[j])   j=reset[j];

        i++;j++;
        if(j==pat.size())
        {
            cout<<"pattern found at "<<i-j<<endl;
            j=reset[j];

        }
    }

}

//////////////////////////////////////////////////

int32_t main()
{
    fast();

    int t=1;    //change t if required
    //cin>>t;
    while(t--)
    {
        memset(reset,-1,sizeof(reset));
        string pat,str;
        cin>>str>>pat;
        kmpSearch(str,pat);
    }

    return 0;
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

