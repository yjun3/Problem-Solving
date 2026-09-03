#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

string s[500010];
int row[500010], col[500010];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int h, w, k; cin >> h >> w >> k;
    vector < vector <int> > vs(h,vector <int>(w,0));
    for(int i=0;i<h;i++){
        cin >> s[i];
        for(int j=0;j<w;j++){
            if(s[i][j] == '#'){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    queue<pair<pair<int, int>, int> > q;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!row[i] && !col[j]){
                q.push({{i, j}, 0});
                vs[i][j] = 1;
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first.first, y = q.front().first.second;
        int t = q.front().second;
        q.pop();

        if(t > k) break;
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(s[nx][ny] == '#' || vs[nx][ny]) continue;
            if(t+1 > k) continue;
            vs[nx][ny] = 1;
            q.push({{nx, ny}, t+1});
        }
    }
    int ans = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(vs[i][j]) ans++;
        }
    }
    cout << ans;
}
