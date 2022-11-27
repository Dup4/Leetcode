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
    int bestClosingTime(string customers) {
        int n = int(customers.size());
        auto f = vector<int>(n + 5, 0);
        auto g = vector<int>(n + 5, 0);

        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] + (customers[i - 1] == 'N');
        }

        for (int i = n; i >= 1; i--) {
            g[i] = g[i + 1] + (customers[i - 1] == 'Y');
        }

        int res = 0;
        int mx = g[1];

        for (int i = 1; i <= n; i++) {
            int cur = f[i] + g[i + 1];
            if (cur < mx) {
                mx = cur;
                res = i;
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
