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

const int mod = 1e9 + 7;

class Solution {
public:
    int countPartitions(vector<int> &nums, int k) {
        int n = int(nums.size());

        auto f = vector<vector<int>>(n + 5, vector<int>(k + 5, 0));
        f[0][0] = 1;

        ll total = 0;
        total = accumulate(all(nums), 0ll);

        int tot = 1;
        for (int i = 0; i < n; i++) {
            tot = tot * 2;
            tot %= mod;
        }

        int res = 0;

        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1];

            int x = nums[i - 1];
            if (x >= k) {
                continue;
            }

            for (int j = 0; j < k; j++) {
                if (x + j < k) {
                    f[i][x + j] += f[i - 1][j];
                    f[i][x + j] %= mod;
                }
            }
        }

        for (int j = 0; j < k; j++) {
            res += f[n][j];
            res %= mod;

            if (total - j >= k) {
                res += f[n][j];
                res %= mod;
            }
        }

        return (tot - res + mod) % mod;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
