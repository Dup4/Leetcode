#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>

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
    bool canChange(string s, string t) {
        int n = int(s.size());
        auto f = vector<pair<char, int>>();
        auto g = vector<pair<char, int>>();

        for (int i = 0; i < n; i++) {
            if (s[i] != '_') {
                f.push_back({s[i], i});
            }

            if (t[i] != '_') {
                g.push_back({t[i], i});
            }
        }

        int m = int(f.size());

        if (m != int(g.size())) {
            return false;
        }

        for (int i = 0; i < m; i++) {
            if (f[i].fi != g[i].fi) {
                return false;
            }

            if (f[i].fi == 'L' && f[i].se < g[i].se) {
                return false;
            }

            if (f[i].fi == 'R' && f[i].se > g[i].se) {
                return false;
            }
        }

        return true;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
