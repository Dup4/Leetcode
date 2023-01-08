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

// 1 1 0 1

class Solution {
public:
    ll s(int x) {
        return 1ll * x * x;
    }

    int xorBeauty(vector<int> &nums) {
        int n = int(nums.size());
        auto f = vector<int>(50, 0);

        for (int x : nums) {
            for (int j = 0; j < 31; j++) {
                if ((x >> j) & 1) {
                    ++f[j];
                }
            }
        }

        int res = 0;
        for (const auto &x : nums) {
            int cur_res = 0;

            for (int j = 0; j < 31; j++) {
                int b = (x >> j) & 1;
                if (b) {
                    ll r = s(n) - s(n - f[j]);
                    if (r & 1) {
                        cur_res |= (1 << j);
                    }
                }
            }

            res ^= cur_res;
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
