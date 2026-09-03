#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

const ll M = 1e9+7;
ll dt[310][310], dt2[310][310];
int a[310];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) dt2[j][k] = dt[j][k];
            for(int j=1;j<=n;j++){
                for(int k=j;k<=n;k++){
                    if(j == k){
                        if(j < a[i]) dt2[a[i]][a[i]] = (dt2[a[i]][a[i]] + dt[j][j])%M;
                        else dt2[a[i]][j] = (dt2[a[i]][j] + dt[j][j])%M;
                    }
                    else{
                        if(k <= a[i]) dt2[j][a[i]] = (dt2[j][a[i]] + dt[j][k])%M;
                        else if(j <= a[i]) dt2[a[i]][k] = (dt2[a[i]][k] + dt[j][k])%M;
                    }
                }
            }
            dt2[a[i]][a[i]] = (dt2[a[i]][a[i]]+1)%M;
            for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) dt[j][k] = dt2[j][k];
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans = (ans + dt[i][j])%M;
                dt[i][j] = 0;
            }
        }
        cout << (ans+1)%M << '\n';
    }
}
