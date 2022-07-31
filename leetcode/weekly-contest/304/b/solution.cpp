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

class Solution {
public:
    int maximumGroups(vector<int> &g) {
        sort(all(g));

        auto v = vector<pair<ll, int>>();

        for (int i = 0; i < int(g.size()); ++i) {
            if (int(v.size()) < 2) {
                v.emplace_back(g[i], 1);
                continue;
            }

            if (int(v.size()) > 1) {
                if (v.end()[-1].fi > v.end()[-2].fi && v.end()[-1].se > v.end()[-2].se) {
                    v.emplace_back(g[i], 1);
                    continue;
                }
            }

            v.back().fi += g[i];
            ++v.back().se;
        }

        while (v.size() >= 2) {
            if (v.end()[-1].fi > v.end()[-2].fi && v.end()[-1].se > v.end()[-2].se) {
                break;
            }

            auto bk = v.back();
            v.pop_back();

            v.back().fi += bk.fi;
            v.back().se += bk.se;
        }

        return int(v.size());
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
