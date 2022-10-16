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
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        ll res = 0;

        int n = int(nums.size());

        int l1 = 0;
        int l2 = 0;
        auto se = multiset<int>();
        auto se2 = multiset<int>();

        for (int i = 0; i < n; i++) {
            int a = nums[i];
            se.insert(a);
            se2.insert(a);

            while (l1 <= i) {
                int mi = *se.begin();
                int mx = *(--(se.end()));

                if (mi < minK || mx > maxK) {
                    se.erase(se.lower_bound(nums[l1]));
                    ++l1;
                } else {
                    break;
                }
            }

            while (l2 < l1) {
                se2.erase(se2.lower_bound(nums[l2]));
                ++l2;
            }

            while (l2 <= i) {
                int mi = *se2.begin();
                int mx = *(--(se2.end()));

                if (mi == minK && mx == maxK) {
                    se2.erase(se2.lower_bound(nums[l2]));
                    ++l2;
                } else {
                    break;
                }
            }

            if (l1 <= i) {
                int mi = *se.begin();
                int mx = *(--(se.end()));

                if (mi == minK && mx == maxK) {
                    // cout << i << " " << l << " " << mi << " " << mx << endl;

                    res += l2 - l1;
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
