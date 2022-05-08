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

const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int f[N], g[N];

class Solution {
public:
    void init() {
        if (f[0] == 1) {
            return;
        }

        f[0] = 1;

        for (int i = 1; i <= 1e5; i++) {
            for (int j = 1; j <= 3; j++) {
                if (i - j >= 0) {
                    f[i] += f[i - j];
                    if (f[i] >= mod) {
                        f[i] -= mod;
                    }
                }
            }
        }

        g[0] = 1;

        for (int i = 1; i <= 1e5; i++) {
            for (int j = 1; j <= 4; j++) {
                if (i - j >= 0) {
                    g[i] += g[i - j];
                    if (g[i] >= mod) {
                        g[i] -= mod;
                    }
                }
            }
        }
    }

    int countTexts(string s) {
        init();

        int res = 1;
        int n = static_cast<int>(s.size());

        int pre = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == pre) {
                ++cnt;
            } else {
                if (pre == '7' || pre == '9') {
                    res = 1ll * res * g[cnt] % mod;
                } else {
                    res = 1ll * res * f[cnt] % mod;
                }

                pre = s[i];
                cnt = 1;
            }
        }

        if (pre == '7' || pre == '9') {
            res = 1ll * res * g[cnt] % mod;
        } else {
            res = 1ll * res * f[cnt] % mod;
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
