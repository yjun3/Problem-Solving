#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int a[200010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        int l, r;
        for(int i=0;i<n;i++){
            if(a[i] == n){
                l = i;
                r = i;
            }
        }
        bool f = true;
        for(int i=n-1;i>=1;i--){
            bool flag = false;
            for(int j=0;j<n;j++){
                if(a[j] == i){
                    if(j == l-1 || j == r+1){
                        if(j == l-1) l--;
                        else r++;
                        flag = true;
                    }
                    break;
                }
            }
            if(!flag) f = false;
        }
        if(!f) cout << "NO\n";
        else cout << "YES\n";
    }
}
