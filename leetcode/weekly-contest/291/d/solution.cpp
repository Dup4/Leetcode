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
    long long appealSum(string s) {
        ll res = 0;
        auto pos = vector<int>(26, -1);

        auto calc = [&](int r) -> ll {
            ll res = 0;

            auto f = vector<int>(pos);

            sort(f.begin(), f.end());
            reverse(f.begin(), f.end());

            int cur = 0;

            for (int i = 0; i < 26; i++) {
                if (f[i] == -1) {
                    break;
                }

                res += 1ll * (r - f[i]) * cur;
                r = f[i];

                ++cur;
            }

            res += 1ll * (r + 1) * cur;

            return res;
        };

        int n = static_cast<int>(s.length());
        for (int i = 0; i < n; i++) {
            char c = s[i];
            pos[c - 'a'] = i;

            res += calc(i);

            // cout << calc(i) << endl;
        }

        // cout << "---" << endl;

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
