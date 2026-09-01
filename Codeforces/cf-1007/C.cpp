#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

vector<int> v[100010], g[100010];

void dfs(int x, int pr){
    for(auto &V:v[x]){
        if(V == pr) continue;
        dfs(V, x);
    }
    cout << x << ' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n, st, en; cin >> n >> st >> en;
        for(int i=1;i<n;i++){
            int p, q; cin >> p >> q;
            v[p].push_back(q);
            v[q].push_back(p);
        }
        dfs(en, -1);
        cout << '\n';
        for(int i=1;i<=n;i++) v[i].clear();
    }
}
