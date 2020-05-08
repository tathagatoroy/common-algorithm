#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void dfs(ll v,ll p,vector<ll> adj[],ll h[],vector<ll> &euler)
{
    ll k=adj[v].size();
    for(ll i=0;i<k;i++)
    {
        ll s=adj[v].at(i);
        if(s!=p)
        {
            h[s]=h[v]+1;
            euler.pb(s);
            dfs(s,v,adj,h,euler);
            euler.pb(v);
        }
    }
}
void build(ll tree[],vector<ll> &euler,ll l,ll r,ll h[],ll v)
{
   // cout<<"building range "<<l<<" "<<r<<" at vertex "<<v<<endl;
    if(l==r)
    {
        tree[v]=euler.at(l);
    }
    else
    {
        ll m=(l+r)/2;
        build(tree,euler,l,m,h,2*v);
        build(tree,euler,m+1,r,h,2*v+1);
        if(h[tree[2*v]]<h[tree[2*v+1]])
        tree[v]=tree[2*v];
        else
        tree[v]=tree[2*v+1];
    }
}
ll query(ll tree[],ll v,ll tl,ll tr,ll l,ll r,ll h[])
{   
 //   cout<<"calling query between "<<l<<" "<<r<<endl;
    if(l>r)
    {
      //   cout<<"calling query between "<<l<<" "<<r<<endl;
       // cout<<"return -1 "<<endl;
        return -1;
    }
    else if(l==tl && r==tr)
    {
         //cout<<"calling query between "<<l<<" "<<r<<endl;
        //cout<<"Returning "<<tree[v]<<endl;
        return tree[v];
    }
    else
    {
        ll tm=(tl+tr)/2;
        ll z=query(tree,2*v,tl,tm,l,min(r,tm),h);
        ll z1=query(tree,2*v+1,tm+1,tr,max(tm+1,l),r,h);
        if(z==-1)
        {
          //   cout<<"calling query between "<<l<<" "<<r<<endl;
           // cout<<"lca "<<z1<<endl;
            return z1;
        }
        else if(z1==-1)
        {
             //cout<<"calling query between "<<l<<" "<<r<<endl;
            //cout<<"lca "<<z<<endl;
            return z;
        }
        else if(h[z]<h[z1])
        {
             //cout<<"calling query between "<<l<<" "<<r<<endl;
            //cout<<"lca "<<z<<endl;
            return z;
        }
        else {
             //cout<<"calling query between "<<l<<" "<<r<<endl;
            //cout<<"lca "<<z1<<endl;
            return z1;
        }
    }
}
ll lca(ll tree[],vector<ll> &euler,ll first[],ll h[],ll u,ll v)
{
    ll z=first[u];
    ll z1=first[v];
    ll k=min(z1,z);
    ll k1=max(z,z1);
    ll sz=euler.size();
   // cout<<z1<<" "<<z<<endl;
return  query(tree,1,0,sz-1,k,k1,h);
}
ll dist(ll u,ll v,ll h[],ll tree[],vector<ll> &euler,ll first[])
{
    ll k=lca(tree,euler,first,h,u,v);
    ll dist=(2*h[k]-h[u]-h[v]);
    return -dist;
}

int main()
{  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> adj[n+1];
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll h[n+1]={0};
    vector<ll> euler;
    euler.pb(1);
    dfs(1,-1,adj,h,euler);
   // euler.pb(1);
    ll first[n+1]={-1};
    for(ll i=0;i<=n;i++)
    first[i]=-1;
    for(ll i=0;i<euler.size();i++)
    {
        if(first[euler.at(i)]==-1)
        first[euler.at(i)]=i;
    }
    ll tree[4*euler.size()+100];
    build(tree,euler,0,euler.size()-1,h,1);
    //for(ll i=0;i<euler.size();i++)
   // cout<<euler.at(i)<<" ";
    //cout<<endl;
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++)
    {
        ll ans=0;
        ll a,b,x,y,k;
        cin>>x>>y>>a>>b>>k;
        ll d1=dist(a,b,h,tree,euler,first);
        ll d2=dist(a,x,h,tree,euler,first)+1+dist(b,y,h,tree,euler,first);
        ll d3=dist(a,y,h,tree,euler,first)+1+dist(b,x,h,tree,euler,first);
        ll z1=d1%2;
        ll z2=d2%2;
        ll z3=d3%2;
        ll z=k%2;
    //    cout<<"d1 "<<d1<<" d2 "<<d2<<" d3 "<<d3<<endl;
        if(d1<=k && z1==z)
        ans=1;
        if(d2<=k && z2==z)
        ans=1;
        if(d3<=k && z3==z)
        ans=1;
        if(ans)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
    return 0;
}
