#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define rall rbegin(a), rend(a)
#define bitcnt(x) (__builtin_popcountll(x))
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define MP make_pair

using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using VLL = std::vector<ll>;
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1e9 + 7;

template <typename T, typename S>
inline bool chmax(T &a, const S &b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T &a, const S &b) {
    return a > b ? a = b, 1 : 0;
}

#ifdef LOCAL
#include <debug.hpp>
#else
#define dbg(...)
#endif
// head

class Solution {
public:
    string minimizeResult(string &e) {
        auto f = vector<int>(2, 0);
        int ix = 0;
        for (int i = 0; i < e.length(); i++) {
            if (e[i] == '+') {
                ++ix;
                continue;
            }

            f[ix] = f[ix] * 10 + (e[i] - '0');
        }

        auto gen = [](int x) -> vector<int> {
            auto res = vector<int>();

            while (x) {
                res.push_back(x % 10);
                x /= 10;
            }

            reverse(all(res));

            return res;
        };

        auto a = gen(f[0]);
        auto b = gen(f[1]);

        int m = 0x3f3f3f3f;
        string res = "";

        auto g = [&](int i, int j) -> tuple<int, string> {
            auto _a = vector<int>(2, 0);
            auto _b = vector<int>(2, 0);

            string res = "";
            for (int o = 0, ix = 0; o < a.size(); o++) {
                if (o == i) {
                    ++ix;
                    res += "(";
                }

                _a[ix] = _a[ix] * 10 + a[o];
                res += char('0' + a[o]);
            }

            res += "+";

            for (int o = 0, ix = 0; o < b.size(); o++) {
                _b[ix] = _b[ix] * 10 + b[o];

                res += char('0' + b[o]);

                if (o == j) {
                    ++ix;
                    res += ")";
                }
            }

            if (_a[0] == 0) {
                _a[0] = 1;
            }

            if (_b[1] == 0) {
                _b[1] = 1;
            }

            return make_tuple(_a[0] * _b[1] * (_a[1] + _b[0]), res);
        };

        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                auto [_m, _res] = g(i, j);
                if (_m < m) {
                    m = _m;
                    res = _res;
                }
            }
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
