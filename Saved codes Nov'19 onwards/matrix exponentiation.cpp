#include <bits/stdc++.h>
using namespace std;

#define print(a)        for (auto x : a) cout << x << " "; cout << endl
#define print_upto(a,n)        for(int i=0;i<n;i++)    cout<<a[i]<<" "; cout<<endl
#define take(x,n)           for(int i=0;i<n;i++)  cin>>x[i];

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
#define pb push_back
#define mp make_pair
#define int long long int
#define N 200005
int ar[N];
//int n,a,b,mod;

int n,k;

vector<vector<int>> multiply(vector<vector<int> >a,vector<vector<int> >b)
{
    vector<vector<int> >c(k,vector<int>(k,0));
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            for(int z=0;z<k;z++)
            {
                c[i][j]+=(a[i][z]*b[z][j]);
                
            }
        }
    }
    return c;
}

vector<vector<int>> powerr(vector<vector<int> >v,int p)
{
    if(p==0)    //not required though, return I matrix
    {
        vector<vector<int> >temp (k,vector<int>(k,0));
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
            {
                if(i==j) temp[i][j]=1;
                else temp[i][j]=0;
            }
        
        return temp;
    
    }
    
    if(p==1)
        return v;

    if(p&1)
        return multiply(v,powerr(v,p-1));
    else
    {
        vector<vector<int> >temp =powerr(v,p/2);
        return multiply(temp,temp);
    }
}

int32_t main()
{
    fast();

    int t=1;    //change t if required
    //cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>k;
    
        vector<vector<int> >v(k,vector<int>(k,0));
            
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(i<k-1)
                {
                    if(j==i+1)
                        v[i][j]=1;
                    else v[i][j]=0;
                    
            
                }
                else v[i][j]=1;
            }
        }

        vector<vector<int> >temp;
        
        int dp[k+1];
        dp[0]=dp[1]=1;
        int cum=1;
        for(int i=2;i<=k;i++)   //1 1 2 3 4 5 6 7 8
        {
            dp[i]=cum+1;
            cum+=dp[i];
        }
        if(n<=k)
        {
            cout<<dp[n];
            return 0;
        }
        
        if(n==k+1)
        {
            int ans=0;
            for(int i=0;i<k;i++)
                ans+=dp[i+1];

        cout<<ans<<endl;
        return 0;
        }
        
      
        temp = powerr(v,n-1);
        int ans=0;
        for(int i=0;i<k;i++)
            ans+=temp[0][i]*dp[i+1];

        cout<<ans<<endl;

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

