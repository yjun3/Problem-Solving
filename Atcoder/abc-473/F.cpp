#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

struct Seg{
    static const int N = 500000;
    ll tree[N*4+10], lazy[N*4+10];

    inline void pro(int n, int l, int r){
        tree[n] += lazy[n];
        if(l != r){
            lazy[n*2] += lazy[n];
            lazy[n*2+1] += lazy[n];
        }
        lazy[n] = 0;
    }

    ll update(int n, int l, int r, int nodel, int noder, ll num){
        // cout << n << ' ' << l << ' ' << r << ' ' << nodel << ' ' << noder << ' ' << num << '\n';
        pro(n, l, r);
        if(noder < l || r < nodel) return tree[n];
        if(nodel <= l && r <= noder){
            lazy[n] += num;
            pro(n, l, r);
            return tree[n];
        }
        int mid = (l+r)>>1;
        return tree[n] = min(update(n<<1, l, mid, nodel, noder, num), update(n<<1|1, mid+1, r, nodel, noder, num));
    }

    ll get(int n, int l, int r, int nodel, int noder){
        pro(n, l, r);
        if(noder < l || r < nodel) return 1e18;
        if(nodel <= l && r <= noder) return tree[n];
        int mid = (l+r)>>1;
        return min(get(n<<1, l, mid, nodel, noder), get(n<<1|1, mid+1, r, nodel, noder));
    }
};
Seg t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    ll sum = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'A') sum++;
        else sum--;
        t.update(1, 1, n, i+1, i+1, sum);
        // cout << t.get(1, 1, n, i+1, i+1) << "!!";
    }
    while(q--){
        int num; cin >> num;
        if(num == 1){
            int i; char c; cin >> i >> c;
            if(s[i-1] != c){
                if(c == 'A') t.update(1, 1, n, i, n, 2);
                else t.update(1, 1, n, i, n, -2);
            }
            s[i-1] = c;
        }
        else{
            int l, r; cin >> l >> r;
            // cout << t.get(1, 1, n, l, r) << ' ' <<  t.get(1, 1, n, l-1, l-1) << ' ';
            if(l > 1 && t.get(1, 1, n, l, r) - t.get(1, 1, n, l-1, l-1) < 0) cout << "No\n";
            else if(l == 1 && t.get(1, 1, n, l, r) < 0) cout << "No\n";
            else cout << "Yes\n";
        }
    }
}
