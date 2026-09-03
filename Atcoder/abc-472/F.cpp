#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

ll x[30010], y[30010];
ll a[30010], b[30010], c[30010];
ll sumA[30010], sumB[30010], sumC[30010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    for(int i=0;i<n;i++) cin >> x[i] >> y[i];
    for(int i=0;i<n;i++){
        int j = (i+1)%n;
        a[i] = (x[i]*y[j]-x[j]*y[i]);
        b[i] = a[i]*(x[i]+x[j]);
        c[i] = a[i]*(y[i]+y[j]);

        sumA[i+1] = sumA[i] + a[i];
        sumB[i+1] = sumB[i] + b[i];
        sumC[i+1] = sumC[i] + c[i];
    }
    cout << fixed;
    cout.precision(12);

    ll A = sumA[n], B = sumB[n], C = sumC[n];
    // cout << B << ' ' << C << endl;
    while(q--){
        int u, v; cin >> u >> v;
        if(u > v){
            swap(u, v);
            ll cA = A - sumA[v-1] + sumA[u-1];
            cA += (x[u-1]*y[v-1]-x[v-1]*y[u-1]);

            ll cB = B - sumB[v-1] + sumB[u-1];
            cB += (x[u-1]*y[v-1]-x[v-1]*y[u-1])*(x[u-1]+x[v-1]);

            ll cC = C - sumC[v-1] + sumC[u-1];
            cC += (x[u-1]*y[v-1]-x[v-1]*y[u-1])*(y[u-1]+y[v-1]);

            double AA = cA, BB = cB, CC = cC;
            // cout << cA << ' ' << cB << ' ' << cC << '\n';
            BB /= (3*AA);
            CC /= (3*AA);
            cout << BB << ' ' << CC << '\n';
        }
        else{
            ll cA = sumA[v-1] - sumA[u-1];
            cA -= (x[u-1]*y[v-1]-x[v-1]*y[u-1]);

            ll cB = sumB[v-1] - sumB[u-1];
            cB -= (x[u-1]*y[v-1]-x[v-1]*y[u-1])*(x[u-1]+x[v-1]);

            ll cC = sumC[v-1] - sumC[u-1];
            cC -= (x[u-1]*y[v-1]-x[v-1]*y[u-1])*(y[u-1]+y[v-1]);

            double AA = cA, BB = cB, CC = cC;
            // cout << cA << ' ' << cB << ' ' << cC << '\n';
            BB /= (3*AA);
            CC /= (3*AA);
            cout << BB << ' ' << CC << '\n';
        }
    }
}
