#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int a[200010], cnt[400010], sum[400010];

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
        int ans = 0;
        for(int i=1;i<=m;i++){
            ans = max(ans, cnt[i] + sum[i+1] + cnt[i*2]);
        }
        for(int i=1;i<=m*2;i++){
            cnt[i] = 0;
            sum[i] = 0;
        }
        cout << ans << '\n';
    }
}
