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
inline bool chmax(T& a, const S& b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T& a, const S& b) {
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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = (int)garbage.size();
        auto g = vector<vector<int>>(3, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (const auto& c : garbage[i]) {
                if (c == 'M') {
                    ++g[0][i];
                } else if (c == 'P') {
                    ++g[1][i];
                } else {
                    ++g[2][i];
                }
            }
        }

        auto calc = [&travel](vector<int>& v) -> int {
            int res = 0;
            while (!v.empty() && v.back() == 0) {
                v.pop_back();
            }

            int m = int(v.size());
            for (int i = 0; i < m; i++) {
                if (i) {
                    res += travel[i - 1];
                }

                res += v[i];
            }

            return res;
        };

        int res = 0;
        for (int i = 0; i < 3; i++) {
            res += calc(g[i]);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
