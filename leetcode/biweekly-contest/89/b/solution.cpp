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

constexpr int mod = 1e9 + 7;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>> &queries) {
        auto f = vector<int>();
        int bit = 1;
        int _n = n;
        while (_n) {
            if (_n & 1) {
                f.push_back(bit);
            }

            bit <<= 1;
            _n >>= 1;
        }

        sort(all(f));

        auto res = vector<int>();

        for (const auto &q : queries) {
            int l = q[0];
            int r = q[1];

            ll cur_res = 1;
            for (int i = l; i <= r; i++) {
                cur_res = 1ll * cur_res * f[i] % mod;
            }

            res.push_back(int(cur_res));
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
