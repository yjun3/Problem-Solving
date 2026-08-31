#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<pair<ll, pair<int, int> > > v;
int par[100010];

int find(int x){
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++) par[i] = i;
    for(int i=0;i<m;i++){
        int p, q; ll w; cin >> p >> q >> w;
        v.push_back({w, {p, q}});
    }
    for(int i=1;i<=n;i++){
        ll w; cin >> w;
        v.push_back({w, {i, 0}});
    }
    sort(v.begin(), v.end());
    ll ans = 0, mn = 1e18, cnt = 0;
    for(auto &V:v){
        int p = V.second.first, q = V.second.second;
        ll w = V.first;
        int pp = find(p), pq = find(q);
        if(pp == pq) continue;
        par[pq] = pp;
        ans += w;
        if(!p || !q){
            cnt++;
            mn = min(mn, w);
        }
    }
    if(cnt == 1) ans -= mn;
    cout << ans;
}
