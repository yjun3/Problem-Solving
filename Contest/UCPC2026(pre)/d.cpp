#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a[200010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll sum = 0, sum2 = 0;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+n);
    for(int i=0;i<n;i+=2) sum2 += a[i];
    cout << sum - sum2*2;
}
