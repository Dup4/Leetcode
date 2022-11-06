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
    long long totalCost(vector<int> &costs, int k, int candidates) {
        int n = int(costs.size());

        auto se = set<pair<int, int>>();
        auto vis = vector<int>(n + 1, 0);

        const auto add = [&vis, &se, &costs, &n](int x) {
            if (x < 0 || x >= n) {
                return;
            }

            if (vis[x] == 1) {
                return;
            }

            vis[x] = 1;
            se.insert(make_pair(costs[x], x));
        };

        int l = candidates - 1;
        int r = n - candidates;

        for (int i = 0; i <= l; i++) {
            add(i);
        }

        for (int i = r; i < n; i++) {
            add(i);
        }

        ll res = 0;

        for (int cnt = 0; cnt < k; cnt++) {
            auto pos = se.begin();
            res += pos->first;
            int pp = pos->second;
            se.erase(pos);

            if (pp <= l) {
                ++l;
                add(l);
            } else {
                --r;
                add(r);
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
