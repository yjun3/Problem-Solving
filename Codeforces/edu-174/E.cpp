// #include <bits/stdc++.h>
// #define all(x) x.begin(), x.end()
// typedef long long ll;
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     int T; cin >> T;
//     while(T--){
//         string s; cin >> s;
//         int a, b, ab, ba; cin >>a  >> b >> ab >> ba;
//         int ca = 0, cb = 0, cab = 0, cba = 0, caba = 0, cbab = 0;
//         for(int i=0;i<s.size();i++){
//             if(s[i] == 'A') ca++;
//             if(s[i] == 'B') cb++;
//             if(i+1 < s.size() && s[i] == 'A' && s[i+1] == 'B') cab++;
//             if(i+1 < s.size() && s[i] == 'B' && s[i+1] == 'A') cba++;
//             if(i+2 < s.size() && s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'A') caba++;
//             if(i+2 < s.size() && s[i] == 'B' && s[i+1] == 'A' && s[i+2] == 'B') cbab++;
//         }
//         int dec = caba + cbab;
//         int must = max(cab - ab, 0) + max(cba - ba, 0);
//         int m = max(max(ca-a, 0), max(cb-b, 0));
//         // cout << m << ' ' << dec << ' ' << must << '\n';
//         if(!m) cout << "YES\n";
//         else if(must <= dec && cab+cba-dec >= m) cout << "YES\n";
//         else cout << "NO\n";
//     }
// }


#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        string s; cin >> s;
        int a, b, ab, ba; cin >> a >> b >> ab >> ba;
        int last = 0, tot = 0, cnt = 0, cnt2 = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'A') cnt++;
            else cnt2++;
        }
        s = s + s[s.size()-1];
        vector<int> vA, vB;
        for(int i=1;i<s.size();i++){
            if(s[i] == s[i-1]){
                int len = i-last;
                if(s[last] == s[i-1]){
                    tot += (len/2);
                }
                else{
                    if(s[last] == 'A') vA.push_back(len);
                    else vB.push_back(len);
                }
                last = i;
            }
        }
        sort(all(vA)), sort(all(vB));

        int useAB = 0, useBA = 0;
        for(auto &V:vA){
            if(V == 2) useAB = min(useAB+1, ab);
            else{
                int x = V/2, can = ab - useAB;
                if(can >= x) useAB += x;
                else{
                    useAB = ab;
                    useBA = min(useBA + (x-can-1), ba);
                }
            }
        }
        for(auto &V:vB){
            if(V == 2) useBA = min(useBA+1, ba);
            else{
                int x = V/2, can = ba - useBA;
                if(can >= x) useBA += x;
                else{
                    useBA = ba;
                    useAB = min(useAB + (x-can-1), ab);
                }
            }
        }

        int use = useAB + useBA;
        int rem = ab-useAB + ba-useBA;
        use += min(rem, tot);
        if(cnt-use <= a && cnt2-use <= b) cout << "YES\n";
        else cout << "NO\n";
    }
}

// Upsolved: 그리디
