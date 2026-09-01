#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int vs[500010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vs[1] = 1;
    vs[8] = 1;
    vs[49] = 1;
    vs[288] = 1;
    vs[1681] = 1;
    vs[9800] = 1;
    vs[57121] = 1;
    vs[332928] = 1;

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        if(vs[n]) cout << -1 << '\n';
        else{
            for(int i=1;i<=n;i++){
                if(vs[i]){
                    cout << i+1 << ' ' << i << ' ';
                    i++;
                }
                else cout << i << ' ';
            }
            cout << '\n';
        }
    }
}
