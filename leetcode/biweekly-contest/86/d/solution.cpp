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

class Solution {
public:
    int maximumRobots(vector<int> &c, vector<int> &r, long long b) {
        int n = int(c.size());

        auto s = vector<ll>(n + 5, 0);
        auto cc = vector<pair<int, int>>();

        int res = 0;

        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + r[i];
            auto _c = make_pair(i, c[i]);
            while (!cc.empty()) {
                if (cc.back().second <= _c.second) {
                    cc.pop_back();
                } else {
                    break;
                }
            }
            cc.push_back(_c);

            int l = 1, r = (i + 1), _res = 0;
            while (r - l >= 0) {
                int mid = (l + r) >> 1;

                ll sum = s[i + 1] - s[i + 1 - mid];
                int cnt = mid;
                auto pos = upper_bound(all(cc), make_pair(i - mid + 1, -1));
                // auto pos = cc.begin();

                // 5 8 9 1

                if (sum * cnt + pos->second <= b) {
                    l = mid + 1;
                    _res = mid;
                } else {
                    r = mid - 1;
                }
            }

            res = max(res, _res);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
