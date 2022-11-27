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
    static inline constexpr int mod = 1e9 + 7;
    int countPalindromes(string s) {
        int n = int(s.size());

        auto f = vector<vector<vector<int>>>(n + 5, vector<vector<int>>(10, vector<int>(10, 0)));
        auto g = vector<vector<vector<int>>>(n + 5, vector<vector<int>>(10, vector<int>(10, 0)));
        auto cnt = vector<int>(20, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    f[i][j][k] = f[i - 1][j][k];
                }
            }

            int num = s[i - 1] - '0';
            for (int j = 0; j < 10; j++) {
                (f[i][j][num] += cnt[j]) %= mod;
            }

            ++cnt[num];
        }

        cnt = vector<int>(20, 0);

        for (int i = n; i >= 1; i--) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    g[i][j][k] = g[i + 1][j][k];
                }
            }

            int num = s[i - 1] - '0';
            for (int j = 0; j < 10; j++) {
                (g[i][num][j] += cnt[j]) %= mod;
            }

            ++cnt[num];
        }

        ll res = 0;
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    res += (1ll * f[i - 1][j][k] * g[i + 1][k][j]) % mod;
                    res %= mod;
                }
            }
        }

        return int(res);
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
