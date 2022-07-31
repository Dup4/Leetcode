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
    int longestCycle(vector<int> &e) {
        int n = int(e.size());

        auto vis = vector<int>(n, 0);
        auto in_sta = vector<int>(n, 0);
        int sta_ix = 0;
        int res = -1;

        auto dfs = [&vis, &in_sta, &sta_ix, &e, &res](auto &&dfs, int u) -> void {
            vis[u] = 1;
            in_sta[u] = ++sta_ix;

            int nx = e[u];

            if (nx != -1) {
                if (in_sta[nx]) {
                    int _res = sta_ix - in_sta[nx] + 1;
                    res = max(res, _res);
                }

                if (!vis[nx]) {
                    dfs(dfs, nx);
                }
            }

            in_sta[u] = 0;
            --sta_ix;
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(dfs, i);
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
