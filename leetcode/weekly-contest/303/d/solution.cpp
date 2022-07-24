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
    long long countExcellentPairs(vector<int> &nums, int k) {
        sort(all(nums));
        nums.erase(unique(all(nums)), nums.end());

        auto f = vector<int>(65, 0);
        auto g = vector<int>(65, 0);

        ll res = 0;
        for (const auto &n : nums) {
            int x = __builtin_popcountll(n);
            f[x]++;
        }

        for (int i = 1; i < 65; i++) {
            g[i] = g[i - 1] + f[i];
        }

        for (int i = 1; i < 65; i++) {
            res += 1ll * f[i] * (g[64] - g[max(0, k - i - 1)]);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
