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

const int mod = 1e9 + 7;

// 1 2 1 3
// 1 2 3 6

class Solution {
public:
    int distinctSequences(int n) {
        static auto f = std::invoke([]() {
            auto f = vector<vector<ll>>(1e4 + 5, vector<ll>(10, 0));
            auto g = vector<vector<ll>>(1e4 + 5, vector<ll>(10, 0));

            const int n = 1e4;

            for (int i = 1; i <= 6; i++) {
                f[1][i] = 1;
                g[1][i] = 1;
            }

            for (int i = 2; i <= n; i++) {
                for (int j = 1; j <= 6; j++) {
                    for (int k = 1; k <= 6; k++) {
                        if (j == k || __gcd(j, k) != 1) {
                            continue;
                        }

                        f[i][j] += f[i - 1][k];
                        f[i][j] %= mod;

                        f[i][j] -= g[i - 2][j];
                        f[i][j] += mod;
                        f[i][j] %= mod;

                        if (i >= 3) {
                            f[i][j] += g[i - 3][k];
                            f[i][j] %= mod;
                        }
                    }

                    g[i][j] = f[i][j] + g[i - 2][j];
                    g[i][j] %= mod;
                }
            }

            return f;
        });

        ll res = 0;
        for (int i = 1; i <= 6; i++) {
            res += f[n][i];
            res %= mod;
        }

        return res;

        // return ans[n - 1];

        // static auto f = std::invoke([]() {
        //     auto res = vector<int>(15);

        //     auto dfs = [&res](auto &&dfs, int n, vector<int> &vec) {
        //         if (vec.size() == (size_t)n) {
        //             ++res[n];
        //             return;
        //         }

        //         for (int i = 1; i <= 6; i++) {
        //             if (!vec.empty()) {
        //                 if (vec.back() == i) {
        //                     continue;
        //                 }

        //                 if (__gcd(vec.back(), i) != 1) {
        //                     continue;
        //                 }

        //                 if (vec.size() >= 2 && vec.end()[-2] == i) {
        //                     continue;
        //                 }
        //             }

        //             vec.push_back(i);
        //             dfs(dfs, n, vec);
        //             vec.pop_back();
        //         }
        //     };

        //     for (int i = 1; i <= 15; i++) {
        //         auto tmp = vector<int>();
        //         dfs(dfs, i, tmp);
        //     }

        //     return res;
        // });

        // return f[n];
    }
};

#ifdef LOCAL

int main() {
    auto s = Solution();
    for (int i = 1; i <= 15; i++) {
        cout << s.distinctSequences(i) << ",";
    }

    return 0;
}

#endif
