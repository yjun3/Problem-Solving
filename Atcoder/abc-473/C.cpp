#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int a[200010], sum[200010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum[a[i]]++;
    }
    int ans = 0, mx = *max_element(sum+1, sum+k+1);
    for(int i=1;i<=k;i++){
        if(mx-1 <= sum[i]) ans++;
    }
    cout << ans;
}
