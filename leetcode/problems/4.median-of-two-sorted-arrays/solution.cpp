#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define rall rbegin(a), rend(a)
#define lowbit(x) ((x) & (-(x)))
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
    int findKth(const vector<int> &nums1, const vector<int> &nums2, int k) {
        int n = int(nums1.size());
        int m = int(nums2.size());

        int l = 0, r = 0;
        while (true) {
            if (l >= n) {
                return nums2[r + k - 1];
            }

            if (r >= m) {
                return nums1[l + k - 1];
            }

            if (k == 1) {
                if (nums1[l] <= nums2[r]) {
                    return nums1[l];
                } else {
                    return nums2[r];
                }
            }

            int mid = min(k / 2, min(n - l, m - r));
            int num1 = nums1[l + mid - 1];
            int num2 = nums2[r + mid - 1];

            if (num1 <= num2) {
                l = l + mid;
                k -= mid;
            } else {
                r = r + mid;
                k -= mid;
            }
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = int(nums1.size());
        int m = int(nums2.size());
        int tot = n + m;

        if (tot & 1) {
            return findKth(nums1, nums2, (tot + 1) / 2);
        } else {
            int num1 = findKth(nums1, nums2, tot / 2);
            int num2 = findKth(nums1, nums2, tot / 2 + 1);

            return (num1 + num2) * 1.0 / 2;
        }
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
