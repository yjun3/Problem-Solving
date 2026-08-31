#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

// SegTree template (Sum ver.)
struct Seg{
    static const int N = 100000;
    ll tree[N*4+10];

    ll update(int n, int l, int r, int node, ll num){
        if(node < l || r < node) return tree[n];
        if(l == r){
            tree[n] = num;
            return tree[n];
        }
        int mid = (l+r)>>1;
        return tree[n] = update(n<<1, l, mid, node, num) + update(n<<1|1, mid+1, r, node, num);
    }

    ll get(int n, int l, int r, int nodel, int noder){
        if(noder < l || r < nodel) return 0ll;
        if(nodel <= l && r <= noder) return tree[n];
        int mid = (l+r)>>1;
        return get(n<<1, l, mid, nodel, noder) + get(n<<1|1, mid+1, r, nodel, noder);
    }
};

// Fenwick template (Sum ver.)
// If it can use Fenwick instead of Segtree, Use it.
struct Fen{
    static const int N = 100000;
    ll tree[N+10];

    void update(int idx, ll num){
        while (idx <= N){
            tree[idx] += num;
            idx += (idx & -idx);
        }
    }

    ll getCnt(int idx){
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

// Mo's Sorting cmp function
int cmp(pair<int, pair<int, int> > x, pair<int, pair<int, int> > y){
    if((x.second.first)/sq == (y.second.first)/sq) return x.second.second < y.second.second;
    return (x.second.first)/sq < (y.second.first)/sq;
}

// Dijkstra
void dijk(int s){
    priority_queue<P, vector<P>, greater<P> > pq;
    fill(dist, dist+n+1, INF);
    fill(vs, vs+n+1, 0);
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        int x = pq.top().second;
        pq.pop();

        if(vs[x]) continue;
        vs[x] = 1;
        for(auto V:v[x]){
            ll nx = V.first, w = V.second;
            if(dist[nx] > dist[x] + w){
                dist[nx] = dist[x] + w;
                pq.push({dist[nx], nx});
            }
        }
    }
    return;
}

// nCr implementation
/*
const ll M = 100003;
ll fac[30010], inv[30010];
ll p(ll x, ll y){
    if(!y) return 1ll;
    if(y == 1) return x;
    ll temp = p(x, y>>1);
    if(y & 1) return ((temp * temp)%M * x)%M;
    else return (temp * temp)%M;
}
ll ncr(int x, int y){
    return ((fac[x] * inv[y])%M * inv[x-y])%M
}
fac[0] = 1;
for(int i=1;i<=n;i++) fac[i] = (fac[i-1] * i) % M;
inv[n] = p(fac[n], M-2);
for(int i=n-1;i>=0;i--) inv[i] = (inv[i+1] * (i+1))%M;
*/

// Mod int
const int M = 998244353;

template <int m, std::enable_if_t<(1 <= m), int> = 0>
struct mint{
public:
    mint() : _v(0) {}
    int val() const { return _v; }
    mint(long long v){
        v %= m;
        if(v < 0) v += m;
        _v = v;
    }
    mint& operator++(){
        _v++;
        if(_v >= m) _v = 0;
        return *this;
    }
    mint& operator--(){
        if(_v == 0) _v = m;
        _v--;
        return *this;
    }
    mint& operator+=(const mint& x){
        _v += x._v;
        if(_v >= m) _v -= m;
        return *this;
    }
    mint& operator-=(const mint& x){
        _v -= x._v;
        if(_v >= m) _v += m;
        return *this;
    }
    mint& operator*=(const mint& x){
        long long t = _v;
        t *= x._v;
        _v = (unsigned int)(t % m);
        return *this;
    }
    mint& operator/=(const mint& x){
        return *this *= x.inv();
    }
    mint inv() const{
        return pow(m-2);
    }
    mint pow(long long x) const{
        mint t = *this, r = 1;
        while(x){
            if(x & 1) r *= t;
            t *= t;
            x >>= 1;
        }
        return r;
    }

    friend mint operator+(const mint& x, const mint& y) {
        return mint(x) += y;
    }
    friend mint operator-(const mint& x, const mint& y) {
        return mint(x) -= y;
    }
    friend mint operator*(const mint& x, const mint& y) {
        return mint(x) *= y;
    }
    friend mint operator/(const mint& x, const mint& y) {
        return mint(x) /= y;
    }
    friend bool operator==(const mint& x, const mint& y) {
        return x._v == y._v;
    }
    friend bool operator!=(const mint& x, const mint& y) {
        return x._v != y._v;
    }

private:
    unsigned int _v = 0;
};

template <typename T>
struct Polynomial{
private:
    vector<T> v;

public:
    Polynomial(){ }
    Polynomial(T val){
        v.push_back(val);
    }
    Polynomial(vector<T> a){
        v = a;
    }

    int size(){
        return v.size();
    }
    void pop_back(){ v.pop_back(); }
    T back(){ return v.back(); }
    T& operator[](int sz){
        if(sz >= v.size()) v.resize(sz+1);
        return v[sz];
    }

    Polynomial operator+(const Polynomial &a) const{
        Polynomial ans;
        for(int i=0;i<v.size();i++) ans[i] += v[i];
        for(int i=0;i<a.size();i++) ans[i] += a[i];
        return ans;
    }
    Polynomial operator-(const Polynomial &a) const{
        Polynomial ans;
        for(int i=0;i<v.size();i++) ans[i] += v[i];
        for(int i=0;i<a.size();i++) ans[i] -= a[i];
        return ans;
    }
    Polynomial operator*(const Polynomial &a) const{
        vector<T> ans = convolution(v, a.v);
        return Polynomial(ans);
    }
    Polynomial operator/(const Polynomial &a) const{
        int sz = v.size();
        Polynomial a_inv = a.inv(sz);
        Polynomial res = Polynomial(v) * a_inv;
        res.truncated(sz);
        return res;
    }
    Polynomial operator*(T val){
        Polynomial ans = Polynomial(v);
        for(int i=0;i<ans.size();i++) ans[i] *= val;
        return ans;
    }
    Polynomial operator/(T val){
        Polynomial ans = Polynomial(v);
        for(int i=0;i<ans.size();i++) ans[i] /= val;
        return ans;
    }
    void truncated(int k){
        while(v.size() > k) v.pop_back();
        while(v.size() < k) v.push_back(0);
    }
    void remove_leading_zero(){
        while(v.size() > 0 && v.back() == 0) v.pop_back();
    }

    Polynomial derivative(int sz){
        while(v.size() > 0 && v.back() == 0) v.pop_back();
        Polynomial ans;
        for(int i=1;i<v.size() && i-1<sz;i++) ans[i-1] = i*v[i];
        ans.truncated(sz);
        return ans;
    }

    Polynomial integral(int sz){
        while(v.size() > 0 && v.back() == 0) v.pop_back();
        Polynomial ans;
        for(int i=0;i<v.size() && i+1<sz;i++) ans[i+1] = v[i]/(i+1);
        ans.truncated(sz);
        return ans;
    }

    vector<T> convolution_naive(const vector<T>& a, const vector<T>& b){
        int n = (int)a.size();
        int m = (int)b.size();
        if(!n || !m) return {};
        vector<T> c(n + m - 1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                c[i + j] += a[i] * b[j];
            }
        }
        return c;
    }

    void ntt(vector<T>& a, bool invert){
        int n = (int)a.size();

        for(int i=1,j=0;i<n;i++){
            int bit = n >> 1;
            for (;j&bit;bit>>=1) j ^= bit;
            j ^= bit;
            if(i < j) swap(a[i], a[j]);
        }

        const int MOD = M;
        const int G = 3;

        for(int len=2;len<=n;len<<=1){
            T wlen = T(G).pow((MOD - 1) / len);
            if(invert) wlen = wlen.inv();
            for(int i=0;i<n;i+=len){
                T w = 1;
                for(int j=0;j<(len >> 1);j++){
                    T u = a[i + j];
                    T v = a[i + j + (len >> 1)] * w;
                    a[i + j] = u + v;
                    a[i + j + (len >> 1)] = u - v;
                    w *= wlen;
                }
            }
        }

        if(invert){
            T inv_n = T(n).inv();
            for(int i=0;i<n;i++) a[i] *= inv_n;
        }
    }

    vector<T> convolution(const vector<T>& a, const vector<T>& b){
        int n = (int)a.size();
        int m = (int)b.size();
        if(!n || !m) return {};

        if(min(n, m) <= 60) return convolution_naive(a, b);

        int sz = 1;
        while(sz < n + m - 1) sz <<= 1;
        vector<T> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        fa.resize(sz);
        fb.resize(sz);

        ntt(fa, false);
        ntt(fb, false);
        for(int i=0;i<sz;i++) fa[i] *= fb[i];
        ntt(fa, true);

        fa.resize(n + m - 1);
        return fa;
    }

    Polynomial inv(int sz){
        while(v.size()>0 && v.back() == 0) v.pop_back();
        assert(v.size()>0);
        assert(v[0]!=0);

        Polynomial g(1/v[0]);

        while(g.size() < sz){
            int gsz = g.size();
            Polynomial h;
            for(int i=0;i<2*gsz && i<v.size();i++) h[i] = v[i];
            h = Polynomial(2) - g*h;
            h.truncated(2*gsz);
            g = g*h;
            g.truncated(2*gsz);
        }
        g.truncated(sz);
        g.remove_leading_zero();
        return g;
    }

    Polynomial log(int sz){
        while(v.size() > 0 && v.back() == 0) v.pop_back();
        assert(v.size() > 0);
        assert(v[0] == 1);

        if(v.size() == 1) return Polynomial(0);
        else{
            Polynomial f2 = Polynomial();
            for(int i=0;i<v.size() && i<sz;i++) f2[i] = v[i];
            Polynomial f1 = f2.derivative(sz);
            Polynomial f3 = f2.inv(sz);
            Polynomial g = f1 * f3;
            g.truncated(sz);
            g = g.integral(sz);
            g[0] = 0;
            g.remove_leading_zero();
            return g;
        }
    }

    Polynomial exp(int sz){
        while(v.size()>0 && v.back()==0) v.pop_back();
        if(v.size() == 0) return Polynomial(1);
        assert(v[0] == 0);

        Polynomial g(1);
        while(g.size() < sz){
            Polynomial h;
            int gsz = g.size();
            for(int i=0;i<2*gsz && i<v.size();i++) h[i] = v[i];
            h = h + Polynomial(1) - g.log(2*gsz<sz?2*gsz:sz);
            h.truncated(2*gsz);
            g = g*h;
            g.truncated(2*gsz);
        }
        g.truncated(sz);
        g.remove_leading_zero();
        return g;
    }

    Polynomial pow(long long k, int sz){
        remove_leading_zero();
        if(k==0) return Polynomial(1);
        int start = -1;
        for(int i=0;i<v.size();i++){
            if(v[i] != 0){
                start = i;
                break;
            }
        }
        if(start==-1) return Polynomial();
        if(start>0){
            if(k>=sz) return Polynomial();
            else if(k*start>=sz) return Polynomial();
        }

        Polynomial P;
        for(int i=start;i<v.size()&&i-start<sz;i++) P[i-start] = v[i];
        T coeff = P[0];
        P = P / coeff;

        P = P.log(sz);
        P = P * k;
        P = P.exp(sz);
        P = P * coeff.pow(k);

        Polynomial ans;
        long long shift = k*start;
        for(int i=0;i<P.size() && shift+i<sz;i++) ans[shift+i] = P[i];
        ans.truncated(sz);
        ans.remove_leading_zero();
        return ans;
    }
};
