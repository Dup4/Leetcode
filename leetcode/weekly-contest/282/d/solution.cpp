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
const ll mod = 1e9 + 7;

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
    int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps) {
        vector<long long> fee(20, INT_MAX), f(numLaps + 10, INT_MAX);
        for (const auto &tire : tires) {
            long long cur = tire[0], inc = tire[1], tot = tire[0];
            for (int i = 1; i <= 18; i++) {
                fee[i] = min(fee[i], tot);
                cur *= inc;
                tot += cur;
                if (tot >= INT_MAX) {
                    break;
                }
            }
        }

        f[0] = 0;

        for (int i = 0; i <= numLaps; i++) {
            for (int j = 1; j <= 18; j++) {
                if (i + j <= numLaps) {
                    f[i + j] = min(f[i + j], f[i] + fee[j] + changeTime);
                }
            }
        }

        return f[numLaps] - changeTime;
    }
};

#ifdef LOCAL

int main() {
    {
        auto s = new Solution();
        auto tires = vector<vector<int>>{
                vector<int>{2, 3},
                vector<int>{3, 4},
        };
        auto ans = s->minimumFinishTime(tires, 5, 4);
        dbg(ans);
    }
    return 0;
}

#endif
