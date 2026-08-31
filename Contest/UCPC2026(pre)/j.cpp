#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

map<int, int> rem;
int a[200010], mn[200010], mx[200010];
int l[200010], r[200010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> v;
    int n, k; cin >> n >> k;
    int idx = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        v.push_back(a[i]);
        rem[a[i]] += 1;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i=0;i<k;i++){
        int x; cin >> x;
        l[i] = idx+1, r[i] = idx+x;
        mx[i] = -1, mn[i] = 1e9+1;
        for(int j=idx+1;j<=idx+x;j++){
            mx[i] = max(mx[i], a[j]);
            mn[i] = min(mn[i], a[j]);
        }
        idx += x;
    }
    int prev=0, chk=0;
    for (ll i=0; i<k; i++) {
        mn[i]=max(prev, mn[i]);
        prev=mn[i];
        if (mn[i]>mx[i]) chk=1;
    }
    prev=1e9+1;
    for (ll i=k-1; i>=0; i--) {
        mx[i]=min(prev, mx[i]);
        prev=mx[i];
        if (mn[i]>mx[i]) chk=1;
    }
    if (chk) {
        cout << -1;
        return 0;
    }

    int pos = 0, pos2 = 0, ans = 0;
    for(int i=1;i<=n;i++){
        if(pos >= k || pos2 >= v.size()){
            ans++;
            continue;
        }

        if(r[pos] < i){
            pos++;
        }
        while(pos < k && pos2 < v.size()){
            if(mn[pos] <= v[pos2] && rem[v[pos2]]) break;
            pos2++;
        }
        if(pos2 < v.size() && mn[pos] <= v[pos2] && v[pos2] <= mx[pos]){
            if(rem[v[pos2]]){
                rem[v[pos2]] -= 1;
                // cout << v[pos2] << ' ';
            }
            else{
                // cout << "? ";
                ans++;
            }
        }
        else{
            // cout << "? ";
            ans++;
        }
    }
    cout << ans;
}
