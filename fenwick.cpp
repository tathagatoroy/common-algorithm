#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less   
using namespace __gnu_pbds;  
using namespace std;  
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> set1;
ll g(ll i)
{
    ll u=i&(i+1);
    return  u;
}
ll sum(vector<ll> t,ll r)
{
    ll sum=0;
    while(r>=0)
    {
        sum+=t.at(r);
        r=g(r)-1;
    }
    return sum;

}
ll update(ll idx,ll delta,ll n,vector<ll> &t)
{
    for(;idx<n;idx=idx|(idx+1))
    t.at(idx)=t.at(idx)+delta;
}
ll build(vector<ll> &t,ll a[],ll n)
{
    t.assign(n,0);
    for(ll i=0;i<n;i++)
    update(i,a[i],n,t);
}
int main()
{

ll a[10]={2,4,5,11,3,2,1,1,9};
vector<ll> t;

build(t,a,10);
cout<<"sum from 4 to 7 "<<sum(t,7)-sum(t,3)<<endl;
cout<<"updating a[6] to 100"<<endl;
update(6,99,10,t);
cout<<"sum from 4 to 7 "<<sum(t,7)-sum(t,3)<<endl;
    return 0;
}
