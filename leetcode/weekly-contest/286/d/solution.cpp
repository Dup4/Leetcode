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
    int maxValueOfCoins(vector<vector<int>> &piles, int k) {
        vector<int> f(k + 1, 0);

        for (int i = 0; i < piles.size(); i++) {
            for (int j = k; j > 0; j--) {
                int v = 0;
                for (int o = 0; o < piles[i].size(); o++) {
                    v += piles[i][o];
                    int w = o + 1;
                    if (j - w >= 0) {
                        f[j] = max(f[j], f[j - w] + v);
                    } else {
                        break;
                    }
                }
            }
        }

        return f[k];
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
