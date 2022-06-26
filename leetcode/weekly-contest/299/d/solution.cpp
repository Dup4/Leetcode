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
    vector<int> f, w;
    vector<vector<int>> g, h;

    void dfs(int u, int fa, vector<int> &fas) {
        int xor_sum = w[u];

        h[u] = vector<int>(fas);
        fas[u] = 1;

        for (auto &v : g[u]) {
            if (v == fa) {
                continue;
            }

            dfs(v, u, fas);
            xor_sum ^= f[v];
        }

        f[u] = xor_sum;
        fas[u] = 0;
    }

    int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
        int n = int(nums.size());

        w = vector<int>(nums);
        f = vector<int>(n + 1, 0);
        g = vector<vector<int>>(n + 1, vector<int>());
        h = vector<vector<int>>(n + 1, vector<int>());

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        auto fas = vector<int>(n + 1, 0);
        dfs(0, 0, fas);

        int res = 2e9;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = i;
                int y = j;

                if (h[y][x]) {
                    swap(x, y);
                }

                auto t = vector<int>();
                t.reserve(3);

                if (h[x][y] == 1) {
                    t.push_back(f[0] ^ f[y]);
                    t.push_back(f[x]);
                    t.push_back(f[y] ^ f[x]);
                } else {
                    t.push_back(f[0] ^ f[x] ^ f[y]);
                    t.push_back(f[x]);
                    t.push_back(f[y]);
                }

                sort(t.begin(), t.end());

                res = min(res, t[2] - t[0]);
            }
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    {
        auto nums = vector<int>({1, 5, 5, 4, 11});
        auto edges = vector<vector<int>>({{0, 1}, {1, 2}, {1, 3}, {3, 4}});
        auto s = Solution();
        auto res = s.minimumScore(nums, edges);
        cout << res << endl;
    }
    return 0;
}

#endif
