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
    long long minCost(vector<int> &nums, vector<int> &cost) {
        int n = int(nums.size());

        int mi = *min_element(all(nums));
        int mx = *max_element(all(nums));

        ll co = 0;
        ll res = 0x3f3f3f3f3f3f3f3f;
        ll left = 0;
        ll right = 0;

        auto f = vector<vector<int>>(mx + 5, vector<int>());

        for (int i = 0; i < n; i++) {
            f[nums[i]].push_back(cost[i]);
            co += 1ll * abs(nums[i] - (mi - 1)) * cost[i];
            right += cost[i];
        }

        for (int i = mi; i <= mx; i++) {
            co -= right;
            co += left;
            for (const auto &a : f[i]) {
                left += a;
                right -= a;
            }

            res = min(res, co);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
