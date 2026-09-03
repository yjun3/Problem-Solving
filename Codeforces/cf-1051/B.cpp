#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

ll a[200010], b[200010];
int vs[200010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n, k; cin >> n >> k;
        int pos = -1;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<k;i++) cin >> b[i];
        sort(a, a+n, greater<>());
        sort(b, b+k);
        for(int i=0;i<k;i++){
            pos += b[i];
            if(pos >= n) break;
            vs[pos] = 1;
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            if(!vs[i]) ans += a[i];
        }
        cout << ans << '\n';

        for(int i=0;i<=n;i++) vs[i] = 0;
    }
}
