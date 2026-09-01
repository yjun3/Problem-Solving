#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int a[110];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        cout << __gcd(a[0], a[n-1]) << '\n';
    }
}
