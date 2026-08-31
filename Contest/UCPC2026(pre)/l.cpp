#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll M = 998244353;

ll ncr[2010][2010], cnt[2010];
ll n, a[2010];
ll dp[2010][2010];
ll tree[2010];

void update(ll x, ll y) {
    ll cur=x;
    while (cur<=n) {
        tree[cur]=(tree[cur] + y)%M;
        cur += (cur & -cur);
    }
}
ll query(ll x) {
    ll res=0;
    ll cur=x;
    while (cur>=1) {
        res=(res + tree[cur])%M;
        cur -= (cur & -cur);
    }
    return res;
}

ll p(ll x, ll y){
    if(!y) return 1ll;
    if(y == 1) return x%M;

    ll temp = p(x, y>>1);
    if(y & 1) return ((temp * temp)%M * x)%M;
    else return (temp * temp) % M;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        ncr[i][0] = 1;
        ncr[i][i] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%M;
        }
    }

    for (ll i=1; i<=n; i++) {
        dp[1][i]=1;
    }
    for (ll i=2; i<=n; i++) {
        for (ll j=1; j<=n; j++) tree[j]=0;
        for (ll j=1; j<=n; j++) {
            if (a[j]<i) {
                dp[i][j]=0;
            }
            else {
                dp[i][j]=query(a[j]-1);
            }
            update(a[j], dp[i-1][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cnt[i] = (cnt[i] + dp[i][j])%M;
        }
    }

    ll ans = n;
    for(int i=1;i<=n;i++){
        ll num = (cnt[i] * p(ncr[n][i], M-2))%M;
        ans = (ans - num + 2*M)%M;
    }
    cout << ans;
}
