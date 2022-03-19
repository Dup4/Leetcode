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
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.length();
        int m = max(n, numCarpets) + 5;

        vector<vector<int>> f(n + 5, vector<int>(numCarpets + 5, 0x3f3f3f3f));
        for (int i = 0; i <= numCarpets; i++) {
            f[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            f[i][0] = f[i - 1][0] + (floor[i - 1] == '1');
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= numCarpets; j++) {
                f[i][j] = min(f[i][j], f[max(0, i - carpetLen)][j - 1]);
                f[i][j] = min(f[i][j], f[i - 1][j] + (floor[i - 1] == '1'));
                f[i][j] = min(f[i][j], f[i][j - 1]);
            }
        }

        return f[n][numCarpets];
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
