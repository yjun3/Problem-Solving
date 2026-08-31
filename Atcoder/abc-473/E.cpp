#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int a[200010], sum[200010];
int dt[200010];
map<int, int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum[i] = (sum[i-1] + a[i])%k;
    }
    mp[0] = 0;
    for(int i=1;i<=n;i++){
        dt[i] = dt[i-1];
        if(mp.find(sum[i]) == mp.end()){
            mp[sum[i]] = dt[i];
        }
        else{
            dt[i] = max(dt[i], mp[sum[i]]+1);
            mp[sum[i]] = dt[i];
        }
    }
    cout << dt[n];
}
