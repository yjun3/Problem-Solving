#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int mp[1010][1010];

int go(int x, int y, int d){
    if(mp[x][y] != -1) return mp[x][y];
    else{
        cout << "? " << x << ' ' << y << ' ' << d << endl;
        int ret; cin >> ret;
        return ret;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) mp[i][j] = -1;
        }
        int ans = 1, x = 2;
        for(int i=2;i<=n;i++){
            while(ans < n){;
                int k = go(1, i, ans);
                if(!k) break;
                else x = i;
                ans++;
            }
        }
        int xx = 1;
        for(int i=1;i<=n;i++){
            if(i == x) continue;
            while(ans < n){;
                int k = go(x, i, ans);
                if(!k) break;
                else xx = i;
                ans++;
            }
        }
        cout << "! " << x << ' ' << xx << ' ' << ans-1 << endl;
    }
}
