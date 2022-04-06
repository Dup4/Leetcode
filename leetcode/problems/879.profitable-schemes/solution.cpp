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
const int mod = 1e9 + 7;

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
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit) {
        auto f = vector<vector<int>>(n + 1, vector<int>(minProfit + 5, 0));
        f[0][0] = 1;

        int m = group.size();
        for (int i = 0; i < m; i++) {
            for (int j = n; j >= 0; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    int w = group[i];
                    int v = profit[i];
                    if (j + w <= n) {
                        int _j = j + w;
                        int _k = (k + v) >= minProfit ? minProfit : (k + v);
                        f[_j][_k] += f[j][k];
                        if (f[_j][_k] >= mod) {
                            f[_j][_k] -= mod;
                        }
                    }
                }
            }
        }

        int res = 0;
        if (minProfit == 0) {
            res += 1;
        }

        for (int i = 1; i <= n; i++) {
            res += f[i][minProfit];
            if (res >= mod) {
                res -= mod;
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
