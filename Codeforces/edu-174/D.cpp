#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int solve(string &s, int l, int r){
    int l2 = s.size()-r-1, r2 = s.size()-l-1;
    int cnt[27] = {0,}, cnt2[27] = {0,};
    for(int i=l;i<=r;i++) cnt[int(s[i]-'a')]++;
    for(int i=l2;i<=r2;i++) cnt2[int(s[i]-'a')]++;

    bool flag = false;
    for(int i=0;i<26;i++){
        if(cnt[i] != cnt2[i]) flag = true;
    }
    if(!flag) return r-l+1;
    for(int i=r+1;i<s.size()/2;i++) cnt[int(s[i]-'a')]++;
    for(int i=s.size()/2;i<l2;i++) cnt2[int(s[i]-'a')]++;
    for(int i=s.size()/2;i<=r2;i++){
        cnt[int(s[i]-'a')]++;
        cnt2[int(s[i]-'a')]--;

        flag = false;
        for(int j=0;j<26;j++){
            if(cnt[j] - cnt2[j] >= 0 && (cnt[j] - cnt2[j])%2 == 0);
            else flag = true;
        }
        if(!flag) return i-l+1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        string s; cin >> s;
        int l = 0, r = s.size()-1;
        while(l < r){
            if(s[l] != s[r]) break;
            l++; r--;
        }
        if(l >= r){
            cout << 0 << '\n';
        }
        else{
            int l2 = s.size()/2-1, r2 = s.size()/2;
            while(l2 >= 0){
                if(s[l2] != s[r2]) break;
                l2--; r2++;
            }
            int ans = solve(s, l, l2);
            reverse(all(s));
            ans = min(ans, solve(s, l, l2));
            cout << ans << '\n';
        }
    }
}
