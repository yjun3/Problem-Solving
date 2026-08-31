#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

vector<int> v;
int n, k;

void solve(int x, int rem){
    if(x == n){
        if(rem % n == 0){
            v.push_back(rem/n);
            for(auto &V:v) cout << V << ' ';
            v.pop_back();
            cout << '\n';
        }
        return;
    }
    for(int i=0;i*x<=rem;i++){
        v.push_back(i);
        solve(x+1, rem-i*x);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    solve(1, k);
}
