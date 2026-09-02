#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

const ll M = 998244353;
int a[200010];
ll dt[4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];

        ll cnt = 0, cnt2 = 0, ans = 0;
        for(int i=0;i<n;i++){
            if(a[i] == 1){
                cnt++;
                cnt2 = (cnt2+1)%M;
            }
            if(a[i] == 2){
                cnt2 = (cnt2*2)%M;
            }
            if(a[i] == 3){
                ans = (ans + cnt2 - cnt + M)%M;
            }
        }
        cout << ans << '\n';
    }
}
