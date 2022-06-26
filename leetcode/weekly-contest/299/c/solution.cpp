#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>
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
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2) {
        auto f = [](vector<int> &nums1, vector<int> &nums2) {
            int res = accumulate(nums1.begin(), nums1.end(), 0);
            res = max(res, accumulate(nums2.begin(), nums2.end(), 0));

            int n = int(nums1.size());

            auto f = vector<int>(n + 5, 0);
            for (int i = n; i >= 1; i--) {
                f[i] = f[i + 1] + nums1[i - 1];
            }

            auto g = vector<vector<int>>(2, vector<int>(n + 5, 0));
            for (int i = 1; i <= n; i++) {
                g[0][i] = g[0][i - 1] + nums1[i - 1];
                g[1][i] = g[1][i - 1] + nums2[i - 1];
            }

            int mx = 0;

            for (int i = 1; i <= n; i++) {
                mx = max(mx, g[0][i] - g[1][i]);
                res = max(res, g[1][i] + f[i + 1] + mx);
            }

            return res;
        };

        int res = f(nums1, nums2);
        res = max(res, f(nums2, nums1));
        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
