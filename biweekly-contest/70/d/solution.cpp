#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define dbg(...)
#endif

using namespace std;
#define endl "\n"
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define Mkp make_pair
#define All(x) (x).begin(), (x).end()
using db = double;
using ll = long long;
using ull = unsigned long long;
using pII = pair<int, int>;
using pLL = pair<ll, ll>;
// head

const int mod = 1e9 + 7;

class Solution {
public:
    int numberOfWays(string corridor) {
        ll res = 1;
        vector<int> v;

        int len = corridor.size();
        for (int i = 0; i < len; i++) {
            if (corridor[i] == 'S') {
                v.push_back(i);
            }
        }

        if (v.empty()) {
            return 0;
        }

        if (v.size() % 2) {
            return 0;
        }

        for (int i = 2; i < v.size(); i += 2) {
            res *= (v[i] - v[i - 1]);
            res %= mod;
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
