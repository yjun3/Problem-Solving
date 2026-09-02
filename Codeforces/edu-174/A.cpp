#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int a[110], p[110];

int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}

void u(int x, int y){
    p[find(x)] = find(y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) p[i] = i;
        for(int i=2;i<n;i++){
            cin >> a[i];
            if(a[i]){
                u(i, i-1);
                u(i+1, i);
            }
        }
        bool flag = false;
        for(int i=2;i<n;i++){
            if(!a[i]){
                if(find(i-1) == find(i) && find(i) == find(i+1)) flag = true;
            }
        }
        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
}
