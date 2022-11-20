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
    inline static constexpr int mod = 1e9 + 7;

    inline static constexpr bool is_prime[] = {
            0,
            0,
            1,
            1,
            0,
            1,
            0,
            1,
            0,
            0,
    };

    int beautifulPartitions(string s, int k, int minLength) {
        int n = int(s.size());

        auto f = vector<vector<int>>(n + 5, vector<int>(k + 5, 0));
        auto g = vector<vector<int>>(n + 5, vector<int>(k + 5, 0));

        f[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];

            for (int o = 0; o <= k; o++) {
                g[i][o] = g[i - 1][o];
            }

            if (!is_prime[c - '0']) {
                int j = i - minLength + 1;

                if (j >= 1) {
                    for (int o = 1; o <= k; o++) {
                        f[i][o] = (f[i][o] + g[j][o - 1]) % mod;
                    }
                }
            }

            for (int o = 0; o <= k; o++) {
                if (is_prime[c - '0']) {
                    g[i][o] = (g[i][o] + f[i - 1][o]) % mod;
                }
            }
        }

        return f[n][k];
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
