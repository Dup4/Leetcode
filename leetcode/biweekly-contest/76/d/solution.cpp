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
inline bool chmax(T& a, const S& b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T& a, const S& b) {
    return a > b ? a = b, 1 : 0;
}

#ifdef LOCAL
#include <debug.hpp>
#else
#define dbg(...)
#endif
// head

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();

        auto f = vector<vector<PII>>(n + 1, vector<PII>(3, PII(-1, -INF)));
        auto G = vector<vector<int>>(n + 1, vector<int>());

        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];

            G[v].push_back(u);
            G[u].push_back(v);
        }

        for (int u = 0; u < n; u++) {
            for (const auto& v : G[u]) {
                int s = scores[v];

                for (int i = 0; i < 3; i++) {
                    if (s > f[u][i].second) {
                        for (int j = 2; j > i; j--) {
                            f[u][j] = f[u][j - 1];
                        }

                        f[u][i] = PII(v, s);
                        break;
                    }
                }
            }
        }

        int res = -1;

        for (int u = 0; u < n; u++) {
            int su = scores[u];

            for (const auto& v : G[u]) {
                int sv = scores[v];

                for (int i = 0; i < 3; i++) {
                    int uu = f[u][i].first;
                    if (uu == -1) {
                        break;
                    }

                    if (uu == v) {
                        continue;
                    }

                    for (int j = 0; j < 3; j++) {
                        int vv = f[v][j].first;
                        if (vv == -1) {
                            break;
                        }

                        if (vv == uu || vv == u) {
                            continue;
                        }

                        int now = su + sv + f[u][i].second + f[v][j].second;

                        res = max(res, now);
                    }
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
