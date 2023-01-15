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

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
        auto f = vector<vector<int>>(n + 5, vector<int>(n + 5, 0));

        for (const auto &q : queries) {
            int x1 = q[0] + 1;
            int y1 = q[1] + 1;
            int x2 = q[2] + 1;
            int y2 = q[3] + 1;

            ++f[x1][y1];
            --f[x1][y2 + 1];
            --f[x2 + 1][y1];
            ++f[x2 + 1][y2 + 1];
        }

        auto res = vector<vector<int>>(n, vector<int>(n, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i) {
                    f[i][j] += f[i - 1][j];
                }

                if (j) {
                    f[i][j] += f[i][j - 1];
                }

                if (i && j) {
                    f[i][j] -= f[i - 1][j - 1];
                }

                res[i - 1][j - 1] = f[i][j];
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
