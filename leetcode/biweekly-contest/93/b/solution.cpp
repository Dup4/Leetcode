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
    int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k) {
        int n = int(vals.size());

        auto f = vector<vector<int>>(n + 5, vector<int>());
        for (const auto &e : edges) {
            int u = e[0];
            int v = e[1];

            f[u].push_back(vals[v]);
            f[v].push_back(vals[u]);
        }

        int res = -0x3f3f3f3f;

        for (int i = 0; i < n; i++) {
            sort(all(f[i]));
            reverse(all(f[i]));

            int cur = vals[i];
            for (int j = 0; j < min(k, int(f[i].size())); j++) {
                if (f[i][j] <= 0) {
                    break;
                }

                cur += f[i][j];
            }

            res = max(res, cur);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif