#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int a[710][710], vs[490010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> a[i][j];
                vs[a[i][j]] = max(vs[a[i][j]], 1);
                if(i && a[i][j] == a[i-1][j]) vs[a[i][j]] = 2;
                if(j && a[i][j] == a[i][j-1]) vs[a[i][j]] = 2;
            }
        }
        int ans = 0, mx = 0;
        for(int i=0;i<=n*m;i++){
            ans += vs[i];
            mx = max(mx, vs[i]);
            vs[i] = 0;
        }
        cout << ans-mx << '\n';
    }
}
