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
    int maxJump(vector<int> &stones) {
        int n = int(stones.size());

        int l = 0, r = abs(stones.end()[-1] - stones[0]), res = -1;

        const auto check = [&](int x) -> bool {
            auto vis = vector<int>(n + 5, 0);

            int pre_ix = 0;
            for (int i = 1; i < n; i++) {
                if (abs(stones[pre_ix] - stones[i]) > x) {
                    if (i - 1 == pre_ix) {
                        return false;
                    }

                    vis[i - 1] = true;
                    pre_ix = i - 1;
                }
            }

            if (stones[n - 1] - stones[pre_ix] > x) {
                return false;
            }

            pre_ix = 0;

            for (int i = 1; i < n; i++) {
                if (!vis[i]) {
                    if (stones[i] - stones[pre_ix] > x) {
                        return false;
                    }

                    pre_ix = i;
                }
            }

            if (stones[n - 1] - stones[pre_ix] > x) {
                return false;
            }

            return true;
        };

        while (r - l >= 0) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
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
