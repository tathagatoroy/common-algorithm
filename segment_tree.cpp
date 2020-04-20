#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void build(ll tree[],ll arr[],ll v,ll l,ll r)
{
    if(l==r)
    tree[v]=arr[l];
    else
    {
       ll m=(l+r)/2;
       build(tree,arr,2*v,l,m);
       build(tree,arr,2*v+1,m+1,r);
       tree[v]=__gcd(tree[2*v],tree[2*v+1]);
    }
}
ll sum(ll tree[],ll v,ll l,ll r,ll tl,ll tr)
{
    if(l>r)
    return 0;
    else if(l==tl && tr==r)
    return tree[v];
    else
    {
        ll tm=(tl+tr)/2;
        ll k1=sum(tree,2*v,l,min(r,tm),tl,tm);
        ll k2=sum(tree,2*v+1,max(l,tm+1),r,tm+1,tr);
        return __gcd(k1,k2);
    }
}
void update(ll tree[],ll v,ll tl,ll tr,ll pos,ll val)
{
    if(tl==tr)
    tree[v]=val;
    else
    {
        ll tm=(tl+tr)/2;
        if(pos<=tm)
        update(tree,2*v,tl,tm,pos,val);
        else
        update(tree,2*v+1,tm+1,tr,pos,val);
        tree[v]=__gcd(tree[2*v],tree[2*v+1]);
    }
}
int main()
{
    ll a[10]={1,2,3,4,5,6,8,8,6,10};
    ll tree[41]={0};
    build(tree,a,1,0,9);
    cout<<sum(tree,1,2,5,0,9)<<endl;
    update(tree,1,0,9,5,100);
    cout<<sum(tree,1,6,8,0,9)<<endl;
    return 0;

}
