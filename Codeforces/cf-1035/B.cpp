#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

ll a[1010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        ll px, py, qx, qy; cin >> px >> py >> qx >> qy;
        ll dist = ((px-qx)*(px-qx)) + ((py-qy)*(py-qy)), sum = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
        }
        if(n == 1){
            if(dist == sum*sum) cout << "Yes\n";
            else cout << "No\n";
        }
        else if(px == qx && py == qy){
            ll mx = *max_element(a, a+n);
            if(mx > sum-mx) cout << "No\n";
            else cout << "Yes\n";
        }
        else{
            ll mx = *max_element(a, a+n);
            // cout << dist << ' ' << sum << '\n';
            if(dist > sum*sum) cout << "No\n";
            else if((2*mx-sum)*(2*mx-sum) > dist && 2*mx-sum >= 0) cout << "No\n";
            else cout << "Yes\n";
        }
    }
}
