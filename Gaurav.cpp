#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,m;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    cin>>m;
    vector<pair<ll,ll>> q;
    for(ll i=0; i<m; i++){
        ll temp1,temp2;
        cin>>temp1>>temp2;
        q.push_back({temp1,temp2});
    }
    vector<ll> ans;
    for(ll i=0; i<n; i++){
        ll x=q[i].first;
        ll y=q[i].second;
        a[x-1]-=y;
        vector<ll> b(n);
        b[0]=a[0];
        for(ll j=1; j<n; j++) b[i]=min(a[i],b[i-1]);
        unordered_set<ll> sol(b.begin(),b.end());
        ans.push_back(sol.size());
    }
    for(ll flag: ans){
        cout<<flag<<endl;
    }
    return 0;
}