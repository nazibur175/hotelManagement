#include<bits/stdc++.h>
#define PI    acos(-1.0)
#define all(x) x.begin(),x.end()
#define nl    '\n'
typedef long long int ll;
typedef unsigned long long int llu;
using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll>v;
        for(ll i=0; i<n; ++i)
        {
            ll j; cin>>j;
            v.push_back(j);
        }

       ll i=0,j=n-1;
       ll l=v.size();
       while(i<j)
       {
         if(v[i]==1 && v[j]==0)
         {
             v[j]=v[j]+1;
             v.erase(v.begin()+i);
            // ei line e ki somossha??
         }
         ++i; --j;
       }
       ll s=v.size();
       cout<<l-s<<nl;
    }
}