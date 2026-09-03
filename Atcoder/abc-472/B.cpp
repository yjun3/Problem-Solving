#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

ll a[200010], vs[200010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    ll k; cin >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    ll sum = 0;
    for(int i=0;i<m;i++){
        if(sum + a[i] > k) cout << "No\n";
        else{
            cout << "Yes\n";
            sum += a[i];
            vs[i] = 1;
        }
    }
    for(int i=m;i<n;i++){
        if(vs[i-m]) sum -= a[i-m];
        if(sum + a[i] > k) cout << "No\n";
        else{
            cout << "Yes\n";
            sum += a[i];
            vs[i] = 1;
        }
    }
}
