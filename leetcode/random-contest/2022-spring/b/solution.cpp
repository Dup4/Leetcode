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
    int perfectMenu(vector<int> &materials, vector<vector<int>> &cookbooks, vector<vector<int>> &attribute, int limit) {
        int res = -1;

        int n = cookbooks.size();

        for (int S = 0; S < (1 << n); S++) {
            auto m = materials;
            int x = 0;
            int y = 0;
            for (int i = 0; i < n; i++) {
                if ((S >> i) & 1) {
                    for (int j = 0; j < 5; j++) {
                        m[j] -= cookbooks[i][j];
                    }

                    x += attribute[i][0];
                    y += attribute[i][1];
                }
            }

            int ok = 1;
            for (int i = 0; i < 5; i++) {
                if (m[i] < 0) {
                    ok = 0;
                }
            }

            if (ok && y >= limit) {
                res = max(res, x);
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
