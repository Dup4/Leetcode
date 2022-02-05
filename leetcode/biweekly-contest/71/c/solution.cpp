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
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        const auto calc = [&](const string &s) -> int {
            int cur = startAt;
            int cost = 0;
            for (const auto &c : s) {
                if (cost == 0 && c == '0') {
                    continue;
                }

                int now = c - '0';
                if (now != cur) {
                    cur = now;
                    cost += moveCost;
                }

                cost += pushCost;
            }

            dbg(s, cost);

            return cost;
        };

        int a = targetSeconds / 60;
        int b = targetSeconds % 60;

        int cost = 99999999;

        if (a <= 99) {
            chmin(cost, calc(to_string(a) + ((b <= 9 ? string("0") : string("")) + to_string(b))));
        }

        if (a >= 1 && b <= 39) {
            chmin(cost, calc(to_string(a - 1) + to_string(b + 60)));
        }

        return cost;
    }
};

#ifdef LOCAL

int main() {
    auto s = new Solution();
    {
        auto ans = s->minCostSetTime(5, 15, 20, 365);
        assert_eq(ans, 90);
    }
    return 0;
}

#endif
