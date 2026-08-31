#include "testlib.h"
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N = opt<int>("n");
    string mode = opt<string>("mode");

    ll maxH = opt<long long>("maxH", 1000000000LL);
    ll maxW = opt<long long>("maxW", 1000000000LL);

    vector<ll> H(N), W(N);

    auto rndH = [&]() -> ll {
        return rnd.next(1LL, maxH);
    };
    auto rndW = [&]() -> ll {
        return rnd.next(1LL, maxW);
    };

    if (mode == "random") {
        for (int i = 0; i < N; i++) {
            H[i] = rndH();
            W[i] = rndW();
        }
    }
    else if (mode == "stair_asc") {
        for (int i = 0; i < N; i++) {
            H[i] = (ll)(i + 1) * (maxH / N);
            W[i] = rndW();
        }
    }
    else if (mode == "stair_desc") {
        for (int i = 0; i < N; i++) {
            H[i] = (ll)(N - i) * (maxH / N);
            W[i] = rndW();
        }
    }
    else if (mode == "inf") {
        for (int i = 0; i < N; i++) {
            W[i] = maxW;
        }
        H[0] = maxH;
        H[N - 1] = maxH;
        for (int i = 1; i < N - 1; i++) {
            H[i] = 1;
        }
    }
    else if (mode == "maxval") {
        for (int i = 0; i < N; i++) {
            H[i] = maxH;
            W[i] = maxW;
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            H[i] = rndH();
            W[i] = rndW();
        }
    }

    cout << N << '\n';
    for (int i = 0; i < N; i++) {
        cout << H[i] << ' ' << W[i] << '\n';
    }

    return 0;
}
