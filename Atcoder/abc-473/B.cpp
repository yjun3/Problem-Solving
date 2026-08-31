#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int a[110], sum[110];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum[a[i]]++;
    }
    int ans = 0;
    for(int i=1;i<=100;i++){
        if(sum[i] & 1) ans += i;
    }
    cout << ans;
}
