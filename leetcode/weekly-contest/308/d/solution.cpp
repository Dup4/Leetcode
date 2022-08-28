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
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions) {
        auto calc = [&k](const vector<vector<int>> &vec) {
            auto g = vector<vector<int>>(k + 1, vector<int>());
            auto d = vector<int>(k + 1, 0);

            for (const auto &v : vec) {
                g[v[0]].push_back(v[1]);
                ++d[v[1]];
            }

            vector<int> ordered, unordered;
            for (int i = 1; i <= k; i++) {
                if (d[i] == 0) {
                    unordered.push_back(i);
                }
            }

            while (!unordered.empty()) {
                int u = unordered.back();
                unordered.pop_back();
                ordered.push_back(u);

                for (int v : g[u]) {
                    if (--d[v] == 0) {
                        unordered.push_back(v);
                    }
                }
            }

            if (int(ordered.size()) != k) {
                return vector<int>();
            }

            auto res = vector<int>(k, 0);
            for (int i = 0; i < k; i++) {
                res[ordered[i] - 1] = i;
            }

            return res;
        };

        auto f = calc(rowConditions);
        auto g = calc(colConditions);

        if (f.empty() || g.empty()) {
            return vector<vector<int>>();
        }

        auto res = vector<vector<int>>(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            res[f[i]][g[i]] = i + 1;
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
