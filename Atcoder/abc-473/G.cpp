#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

const ll M = 998244353;

ll p(ll x, ll y){
    if(!y) return 1ll;
    if(y == 1) return x;
    ll temp = p(x, y>>1);
    if(y & 1) return ((temp * temp)%M * x)%M;
    else return (temp * temp)%M;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n = 50000, k = 77777;
    ll fac = 1;
    for(ll i=1;i<=n;i++){
        fac = (fac * i)%M;
    }
    cout << (ll(251612105) * fac)%M;
}

// Upsolved: FFT 지식 필요
