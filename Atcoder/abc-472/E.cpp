#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

vector<int> v[200010];
int c[200010], pr[200010], vs[200010];
vector<int> ans, ans2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        for(int i=0;i<m;i++){
            int p, q; cin >> p >> q;
            v[p].push_back(q);
            v[q].push_back(p);
        }
        int st = -1, ed = -1;
        queue<pair<int, int> > q;
        c[1] = 2; pr[1] = -1;
        q.push({1, 2});
        while(!q.empty()){
            int x = q.front().first, color = q.front().second;
            q.pop();

            for(auto &V:v[x]){
                if(c[V]){
                    if(c[V] == color){
                        st = x;
                        ed = V;
                        break;
                    }
                }
                else{
                    pr[V] = x;
                    c[V] = color^1;
                    q.push({V, color^1});
                }
            }
            if(st != -1) break;
        }
        if(st == -1) cout << -1 << '\n';
        else{
            int xx = st;
            while(xx != -1){
                vs[xx] = 1;
                xx = pr[xx];
            }
            xx = ed;
            int lca = -1;
            while(xx != -1){
                if(vs[xx]){
                    lca = xx;
                    break;
                }
                vs[xx] = 1;
                xx = pr[xx];
            }
            xx = st;
            while(xx != lca){
                ans.push_back(xx);
                xx = pr[xx];
            }
            xx = ed;
            while(xx != lca){
                ans2.push_back(xx);
                xx = pr[xx];
            }
            ans2.push_back(lca);
            reverse(all(ans2));
            cout << ans.size()+ans2.size() << '\n';
            for(auto &V:ans) cout << V << ' ';
            for(auto &V:ans2) cout << V << ' ';
            cout << '\n';
        }

        ans.clear();
        ans2.clear();
        for(int i=1;i<=n;i++){
            c[i] = 0;
            vs[i] = 0;
            pr[i] = 0;
            v[i].clear();
        }
    }
}
