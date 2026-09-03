#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

const ll M = 1e9+7;
int a[2010];

// Fenwick template (Sum ver.)
// If it can use Fenwick instead of Segtree, Use it.
struct Fen{
    static const int N = 2000;
    ll tree[N+10];

    void update(int idx, ll num){
        while (idx <= N){
            tree[idx] += num;
            idx += (idx & -idx);
        }
    }

    ll get(int idx){
        ll cnt = 0;
        if (idx < 1) return 0;
        if (idx > N) idx = N;

        while (idx > 0){
            cnt += tree[idx];
            idx -= (idx & -idx);
        }
        return cnt;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<vector<ll>> dt(n+1, vector<ll>(n+1, 0ll));
        vector<vector<ll>> dt2(n+1, vector<ll>(n+1, 0ll));
        vector<Fen> t1(n+1), t2(n+1);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++){
            for(int j=1;j<a[i];j++){
                dt2[j][a[i]] = (dt2[j][a[i]] + t1[j].get(a[i]) - t1[j].get(j))%M;
            }
            for(int k=a[i]+1;k<=n;k++){
                dt2[a[i]][k] = (dt2[a[i]][k] + t2[k].get(a[i]))%M;
            }
            for(int j=1;j<=n;j++){
                if(j < a[i]) dt2[a[i]][a[i]] = (dt2[a[i]][a[i]] + dt[j][j])%M;
                else dt2[a[i]][j] = (dt2[a[i]][j] + dt[j][j])%M;
            }
            dt2[a[i]][a[i]] = (dt2[a[i]][a[i]]+1)%M;

            for(int j=1;j<=n;j++){
                if(j < a[i]){
                    t1[a[i]].update(a[i], dt2[a[i]][a[i]] - dt[a[i]][a[i]]);
                    t2[a[i]].update(a[i], dt2[a[i]][a[i]] - dt[a[i]][a[i]]);
                    dt[a[i]][a[i]] = dt2[a[i]][a[i]];
                }
                else{
                    t1[a[i]].update(j, dt2[a[i]][j] - dt[a[i]][j]);
                    t2[j].update(a[i], dt2[a[i]][j] - dt[a[i]][j]);
                    dt[a[i]][j] = dt2[a[i]][j];
                }
            }
            for(int j=1;j<a[i];j++){
                t1[j].update(a[i], dt2[j][a[i]] - dt[j][a[i]]);
                t2[a[i]].update(j, dt2[j][a[i]] - dt[j][a[i]]);
                dt[j][a[i]] = dt2[j][a[i]];
            }
            for(int k=a[i]+1;k<=n;k++){
                t1[a[i]].update(k, dt2[a[i]][k] - dt[a[i]][k]);
                t2[k].update(a[i], dt2[a[i]][k] - dt[a[i]][k]);
                dt[a[i]][k] = dt2[a[i]][k];
            }
            dt[a[i]][a[i]] = dt2[a[i]][a[i]];
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans = (ans + dt[i][j])%M;
            }
        }
        cout << (ans+1)%M << '\n';
    }
}

// Upsolved: Segtree time issue Sibal
