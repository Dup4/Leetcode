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
    vector<int> smallestSubarrays(vector<int> &nums) {
        int n = int(nums.size());
        auto res = vector<int>(n, 0);
        auto f = vector<int>(35, 0);

        int r = n - 1;

        const auto add = [&f](int x) {
            for (int i = 0; i < 31; i++) {
                f[i] += ((x >> i) & 1);
            }
        };

        const auto tryDel = [&f](int x) {
            bool ok = true;
            for (int i = 0; i < 31; i++) {
                if ((x >> i) & 1) {
                    if (f[i] < 2) {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok) {
                for (int i = 0; i < 31; i++) {
                    f[i] -= ((x >> i) & 1);
                }
            }

            return ok;
        };

        for (int i = n - 1; i >= 0; i--) {
            add(nums[i]);
            while (r > i) {
                if (tryDel(nums[r])) {
                    --r;
                } else {
                    break;
                }
            }

            res[i] = (r - i + 1);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
