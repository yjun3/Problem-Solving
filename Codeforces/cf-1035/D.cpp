#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int n;
ll m;
ll dt[5010][5010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        cin >> n >> m;
        dt[0][0] = 1;
        for(int i=1;i<=n;i++){
            dt[i][0] = 1;
            for(int j=1;j<=i;j++){
                dt[i][j] = (dt[i-1][j] + dt[i-1][j-1]*(n-i+1)*(i-j+1))%m;
            }
        }
        ll ans = 0;
        for(int i=0;i<=n;i++) ans = (ans + dt[n][i])%m;
        cout << ans << '\n';

        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=n+1;j++) dt[i][j] = 0;
        }
    }
}

// Upsolved: n^2 dp
