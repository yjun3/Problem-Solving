#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        ll n, l, r, k; cin >> n >> l >> r >> k;
        if(n & 1){
            cout << l << '\n';
            continue;
        }
        ll num;
        for(ll i=0;;i++){
            num = (1ll << i);
            if(num > r && !(num & r)) break;
        }
        num >>= 1;
        if((num & l)) cout << -1 << '\n';
        else if(n == 2) cout << -1 << '\n';
        else{
            ll temp = r;
            for(ll i=0;;i++){
                ll num = (1ll << i);
                if(num > l && !(num & l)){
                    temp = num;
                    break;
                }
            }
            if(n-1 <= k && k <= n){
                if(l <= temp && temp <= r) cout << temp << '\n';
                else cout << -1 << '\n';
            }
            else cout << l << '\n';
        }
    }
}
