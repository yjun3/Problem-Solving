#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

ll a[200010], cnt[200010], sum[200010];
ll dt[200010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        for(int i=0;i<n;i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
        for(int i=m;i>=1;i--) sum[i] = sum[i+1] + cnt[i];

        ll p = 2, k = m/2;
        for(int i=1;i<=m;i++){
            ll ans = 0;
            for(int j=1;j<=max(k, 1ll);j++){
                if(p*j<=m) dt[j] += cnt[p*j];
                for(int l=p/2;l<p;l++){
                    if(j*l > m) break;
                    dt[j] += sum[j*l];
                }
                ans = max(ans, dt[j]);
            }
            cout << ans << ' ';
            for(int j=1;j<=max(k, 1ll);j++){
                if(p*j<=m) dt[j] -= cnt[p*j];
            }
            if(p <= m*2) p *= 2;
            k /= 2;
        }
        for(int i=1;i<=m+1;i++){
            cnt[i] = 0;
            sum[i] = 0;
            dt[i] = 0;
        }
        cout << '\n';
    }
}
