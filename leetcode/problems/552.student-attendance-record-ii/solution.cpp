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
const int mod = 1e9 + 7;

template <typename T, typename S>
inline bool chmax(T &a, const S &b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T &a, const S &b) {
    return a > b ? a = b, 1 : 0;
}

template <typename T>
inline void chmod(T &a, const T &b) {
    a += b;
    if (a > mod) {
        a -= mod;
    }
}

#ifdef LOCAL
#include <debug.hpp>
#else
#define dbg(...)
#endif
// head

const int N = 1e5 + 10;
int f[N][3][4];

class Solution {
public:
    int checkRecord(int n) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 4; k++) {
                    f[i][j][k] = 0;
                }
            }
        }

        f[0][0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    chmod(f[i][j][0], f[i - 1][j][k]);

                    if (j) {
                        chmod(f[i][j][0], f[i - 1][j - 1][k]);
                    }

                    if (k) {
                        chmod(f[i][j][k], f[i - 1][j][k - 1]);
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                chmod(res, f[n][i][j]);
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
