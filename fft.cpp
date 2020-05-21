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
#define cd complex<double>
const double pi=acos(-1);
void fft(vector<cd> &a)
{
    ll n=a.size();
 //   cout<<" fft of size "<<n<<endl;
    if(n==1)
    {
      //  cout<<"returning size "<<1<<endl;

        return ;
    }
    else
    {
        vector<cd> a0;
        vector<cd> a1;
        for(ll i=0;i<n;i=i+2)
        {
            a0.pb(a.at(i));
            a1.pb(a.at(i+1));
        }
        fft(a0);
        fft(a1);
        double ang=(2*pi)/n;
        cd w(1);
        cd wn(cos(ang),sin(ang));
        for(ll i=0;i<n/2;i++)
        {
            a.at(i)=a0.at(i)+w*a1.at(i);
           a.at(i+n/2)=a0.at(i)-w*a1.at(i);
           w=w*wn;
        }
    }
  //  cout<<" returning size "<<n<<endl;
}
void invert(vector<cd> &a)
{
   ll n=a.size();
    if(n==1)
    return;
    else
    {
        vector<cd> a0,a1;
        for(ll i=0;i<n;i=i+2)
        {
            a0.pb(a.at(i));
            a1.pb(a.at(i+1));
        }
        invert(a0);
        invert(a1);
        double ang=(-2*pi)/n;
        cd w(1);
        cd wn(cos(ang),sin(ang));
        for(ll i=0;i<n/2;i++)
        {
            a.at(i)=a0.at(i)+w*a1.at(i);
            a.at(i+n/2)=a0.at(i)-w*a1.at(i);
            a.at(i)/=2;
            a.at(i+n/2)/=2;
            w=w*wn;
        }

    }
}
void mul(vector<ll> a,vector<ll> b,vector<ll> &res1)
{
    vector<cd> a1;
    vector<cd> b1;
    ll u=a.size();
    ll v=b.size();
    ll k=u+v;
    ll sz=1;

//    ll r=1;
    while(sz<k)
    {
        sz*=2;
    }
   // cout<<sz<<" "<<u<<" "<<v<<endl;
    for(ll i=0;i<u;i++)
    {
        cd w((double)a.at(i),0.00);
        a1.pb(w);
    }
    for(ll i=u;i<sz;i++)
    {
        cd w(0.0,0.0);
        a1.pb(w);
    }
    for(ll i=0;i<v;i++)
    {
        cd w((double)b.at(i),0.00);
        b1.pb(w);
    }
    for(ll i=v;i<sz;i++)
    {
        cd w(0.0,0.0);
        b1.pb(w);
    }
   // cout<<"before "<<endl;
    fft(a1);
    fft(b1);
   /// cout<<"here"<<endl;
    vector<cd> res;
    for(ll i=0;i<sz;i++)
    {
        cd u=a1.at(i)*b1.at(i);
        res.pb(u);
    }
  ////  cout<<" check "<<endl;
    invert(res);
   // cout<<" uncheck"<<endl;
    for(ll i=0;i<sz;i++)
    res1.pb(round(res.at(i).real()));

}
int main()
{
    vector<ll> a;
    vector<ll> b;
    vector<ll> c;
    ll a1;
    ll b1;
    cout<<" size of a"<<endl;
    cin>>a1;
    cout<<" a "<<endl;
    for(ll i=0;i<a1;i++)
    {
        ll k;
        cin>>k;
        a.pb(k);
    }
    cout<<" size of b"<<endl;
    cin>>b1;
    cout<<" b "<<endl;
    for(ll i=0;i<b1;i++)
    {
        ll k;
        cin>>k;
        b.pb(k);
    }
    mul(a,b,c);
    cout<<"a*b:"<<endl;
    ll k=c.size();
    for(ll i=0;i<k;i++)
    cout<<c.at(i)<<" ";
    cout<<endl;
    return 0;

}
