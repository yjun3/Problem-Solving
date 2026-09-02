#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        ll a, b, x, y; cin >> a >> b >> x >> y;
        if(a > b){
            if((a^1) == b) cout << y << '\n';
            else cout << -1 << '\n';
        }
        else if(a == b) cout << 0 << '\n';
        else{
            if(x <= y) cout << (b-a)*x << '\n';
            else{
                ll ans = (x+y) * ((b-a)/2);
                if((b-a)%2 == 1){
                    if(b & 1) ans += y;
                    else ans += x;
                }
                cout << ans << '\n';
            }
        }
    }
}
