#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

ll H[1000010];
ll sumH[1000010];
ll l[1000010], r[1000010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    ll M = -1, sumW = 0;
    for(int i=1;i<=N;i++){
        ll W; cin >> H[i] >> W;
        sumW += W;
        M = max(M, H[i]);
        sumH[i] = sumH[i - 1] + H[i];
    }

    ll mx = 0;
    for(int i=1;i<=N;i++) {
        mx = max(mx, H[i]);
        l[i] = l[i - 1] + (mx - H[i]);
    }
    mx = 0;
    for(int i=N;i>=1;i--) {
        mx = max(mx, H[i]);
        r[i] = r[i + 1] + (mx - H[i]);
    }

    ll ans = 2 * sumW + 2 * M;
    ll ansCost = (1LL << 62);

    ll best = 0;
    for(int i=1;i<=N;i++){
        ll candL = l[i - 1] + sumH[i - 1] - M * (i - 1);
        best = min(best, candL);

        ll cand = best + (r[i + 1] - sumH[i] + M * i);
        ansCost = min(ansCost, cand);
    }

    cout << ans << ' ' << ansCost << '\n';
    return 0;
}
