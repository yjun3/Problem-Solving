#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

vector<int> v[200010];
int cnt[200010], ans[200010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        for(int i=1;i<n;i++){
            int p, q, x, y; cin >> p >> q >> x >> y;
            if(x < y){
                v[p].push_back(q);
                cnt[q]++;
            }
            else{
                v[q].push_back(p);
                cnt[p]++;
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(!cnt[i]) q.push(i);
        }
        int num = 1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans[x] = num++;

            for(auto &V:v[x]){
                cnt[V]--;

                if(!cnt[V]) q.push(V);
            }
        }
        for(int i=1;i<=n;i++) cout << ans[i] << ' ';
        cout << '\n';

        for(int i=0;i<=n;i++){
            v[i].clear();
            cnt[i] = 0;
        }
    }
}
