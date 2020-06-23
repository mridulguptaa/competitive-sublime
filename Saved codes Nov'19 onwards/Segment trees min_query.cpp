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
//#define int long long int
#define N 100001
int ar[N];
int n,a,b,k,mod;
vec(int) v;

void build_tree(int *ar,int s,int e,int*tree,int index)
{
    if(s==e)
    {
        tree[index]=ar[s];
        return;
    }

    int mid=(s+e)/2;
    build_tree(ar,s,mid,tree,2*index);
    build_tree(ar,mid+1,e,tree,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}

int query(int *tree,int ss,int se,int qs,int qe,int index)
{
    if(ss>=qs && se<=qe)
        return tree[index];
    if(qe<ss or qs>se)
        return INT_MAX;
    else
    {
        int mid=(ss+se)/2;
        int left = query(tree,ss,mid,qs,qe,2*index);
        int right = query(tree,mid+1,se,qs,qe,2*index+1);

        return min(left,right);
    }
}

void update(int *tree,int ss,int se,int i,int increment,int index)
{
    if(i>se or i<ss)
        return;

    if(ss==se)
    {
        tree[index]+=increment;
        return;
    }

    int mid=(se+ss)/2;
    update(tree,ss,mid,i,increment,2*index);
    update(tree,mid+1,se,i,increment,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}

void update_range(int*tree,int ss,int se,int l,int r,int inc,int index)
{
    if(l>se or r<ss)
        return;
    if(ss==se)
    {
        tree[index]+=inc;
        return;
    }

    int mid=(se+ss)/2;
    update_range(tree,ss,mid,l,r,inc,2*index);
    update_range(tree,mid+1,se,l,r,inc,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;

}

void updateLazyRange(int*tree,int ss,int se,int l,int r,int inc,int index,int*lazy)
{
    if(lazy[index]!=0)
    {
        tree[index]+=index;

        if(ss!=se)
        {
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }

    if(r<ss or l>se)
        return;
    if(ss>=l and se<=r)
    {
        tree[index]+=inc;

        if(ss!=se)
        {
            lazy[2*index]+=inc;
            lazy[2*index+1]+=inc;
        }
        return;
    }

    int mid=(ss+se)/2;
    updateLazyRange(tree,ss,mid,l,r,inc,index*2,lazy);
    updateLazyRange(tree,mid+1,se,l,r,inc,index*2+1,lazy);
    return;
}


int querylazy(int*tree,int ss,int se,int qs,int qe,int index,int*lazy)
{
    if(lazy[index]!=0)
    {
        tree[index]+=lazy[index];
        if(ss!=se)
        {
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        
        lazy[index]=0;
    }
        
    if(ss>qe or se<qe)
        return INT_MAX;
    if(ss>=qs or se<=qe)
    {
        return tree[index];
    }

    int mid=(ss+se)/2;
    int left=querylazy(tree,ss,mid,qs,qe,2*index,lazy);
    int right = querylazy(tree,mid+1,se,qs,qe,2*index+1,lazy);

    return min(left,right);

}

int32_t main()
{
    fast();

    int t=1;    //change t if required
    //cin>>t;
    while(t--)

    {
        cin>>n;
        take(ar,n);
        
        int *tree=new int[4*n+1];
        int *lazy=new int[4*n+1];
        memset(tree,-1,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        build_tree(ar,0,n-1,tree,1);
        /*
        print_upto(tree,14);

        int qe,qs;
        cin>>qs>>qe;
        cout<<query(tree,0,n-1,qs,qe,1)<<endl;
        int i,how;
        cin>>i>>how;/
        update(tree,0,n-1,i,how,1);
        cout<<query(tree,0,n-1,0,2,1);
        update_range(tree,0,n-1,0,2,-10,1);
        cout<<"working ";
        cout<<query(tree,0,n-1,4,4,1);
        cout<<query(tree,0,n-1,0,4,1);
        cout<<endl;
        //updateLazyRange(tree,0,n-1,0,4,-15,1,lazy);
        cout<<querylazy(tree,0,n-1,0,4,1,lazy);
        */      
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

