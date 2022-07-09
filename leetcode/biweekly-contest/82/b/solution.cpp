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
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
        sort(all(buses));
        sort(all(passengers));

        int n = int(buses.size());
        int m = int(passengers.size());

        auto vis = map<int, bool>();

        int res = 1;
        for (int i = 0, j = -1; i < n; ++i) {
            int o = 0;
            for (; o < capacity && j + 1 < m && passengers[j + 1] <= buses[i];) {
                o++;
                j++;

                vis[passengers[j]] = 1;
                if (vis[passengers[j] - 1] == 0) {
                    res = max(res, passengers[j] - 1);
                }
            }

            if (o + 1 <= capacity && vis[buses[i]] == 0) {
                res = max(res, buses[i]);
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
