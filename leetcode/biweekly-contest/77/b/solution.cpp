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
    int minimumAverageDifference(vector<int> &nums) {
        size_t n = nums.size();
        auto pre = vector<ll>(n + 5, 0);
        for (size_t i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        auto suffix = vector<ll>(n + 5, 0);
        for (size_t i = n; i >= 1; i--) {
            suffix[i] = suffix[i + 1] + nums[i - 1];
        }

        ll m = 0x3f3f3f3f;
        int idx = -1;

        for (size_t i = 1; i <= n; i++) {
            ll a = static_cast<ll>(pre[i] / i);
            ll b = 0;

            if (n - i > 0) {
                b = static_cast<ll>(suffix[i + 1] / (n - i));
            }

            ll cur = abs(a - b);

            if (cur < m) {
                m = cur;
                idx = static_cast<int>(i - 1);
            }
        }

        return idx;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
