#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define rall rbegin(a), rend(a)
#define lowbit(x) ((x) & (-(x)))
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

constexpr int N = 110;
vector<bool> has;

class Solution {
public:
    bool checkValid(vector<vector<int>> &matrix) {
        size_t n = matrix.size();

        constexpr auto ok = [](const vector<bool> &has) {
            size_t n = has.size();
            for (int i = 1; i < n; ++i) {
                if (!has[i]) {
                    return false;
                }
            }

            return true;
        };

        for (int i = 0; i < n; i++) {
            has = vector<bool>(n + 1, false);
            for (int j = 0; j < n; j++) {
                has[matrix[i][j]] = 1;
            }

            if (!ok(has)) {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            has = vector<bool>(n + 1, false);
            for (int j = 0; j < n; j++) {
                has[matrix[j][i]] = 1;
            }

            if (!ok(has)) {
                return false;
            }
        }

        return true;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
