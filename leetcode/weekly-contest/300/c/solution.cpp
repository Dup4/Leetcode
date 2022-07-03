#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>

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

constexpr int mod = 1e9 + 7;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        auto f = vector<int>(n + 1, 0);
        auto g = vector<int>(n + 1, 0);
        auto h = vector<int>(n + 1, 0);

        g[1] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = i + delay; j <= min(n, i + forget - 1); j++) {
                g[j] += g[i];
                g[j] %= mod;
            }

            if (i + forget <= n) {
                h[i + forget] += g[i];
                h[i + forget] %= mod;
            }

            f[i] += (f[i - 1] + g[i]) % mod;
            f[i] %= mod;
            f[i] -= h[i];
            f[i] += mod;
            f[i] %= mod;
        }

        return f[n];
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
