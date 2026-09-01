#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

ll p, s;
int a[200010];

void solve(ll pos, ll sz){

    if(pos <= sz){
        p = pos, s = sz;
        return;
    }
    else{
        solve(pos-sz, sz*2);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int n; ll l, r; cin >> n >> l >> r;
        int x = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        if(n == 1){
            n = 3;
            a[2] = a[1];
            a[3] = a[1];
        }
        else if(n % 2 == 0){
            for(int i=1;i<=(n+1)/2;i++) x ^= a[i];
            a[n+1] = x;
            n++;
        }

        if(l <= n) cout << a[l] << '\n';
        else{
            x = 0;
            for(int i=1;i<=n;i++) x ^= a[i];
            solve(l-n, n+1);

            vector<ll> v;
            while(s >= n+1){
                v.push_back(p);
                p = (p+1)/2;
                s /= 2;
            }
            reverse(all(v));
            int fs = x;
            x = 0;
            for(int i=1;i<=(v[0]+n)/2;i++){
                x ^= a[i];
            }
            int k = x;
            for(int i=0;i<v.size()-1;i++){
                int V = v[i];
                if(V & 1){
                    if(fs){
                        k ^= 1;
                    }
                }
                else{
                    if(fs == 0) k = 0;
                    else k = 1;
                }
            }
            cout << k << '\n';
        }
    }
}
