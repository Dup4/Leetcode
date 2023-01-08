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

const ll INF = 0x3f3f3f3f3f3f3f3f;

class Solution {
public:
    long long maxPower(vector<int> &sta, int r, int k) {
        int n = int(sta.size());

        auto need_ori = vector<ll>(n + 5, 0);
        for (int i = 0; i < n; i++) {
            int _l = max(0, i - r);
            int _r = min(n, i + r + 1);
            need_ori[_l] += sta[i];
            need_ori[_r] -= sta[i];
        }

        auto ok = [&](ll x) -> bool {
            ll cur = 0;
            auto need = need_ori;
            ll has = k;

            for (int i = 0; i < n; i++) {
                cur += need[i];

                if (cur >= x) {
                    continue;
                }

                ll diff = x - cur;
                if (has < diff) {
                    return false;
                }

                has -= diff;

                int pos = min(n, i + r + r + 1);
                need[pos] -= diff;

                cur += diff;
            }

            return true;
        };

        ll l = 0, rr = INF, res = -1;
        while (rr - l >= 0) {
            ll mid = (l + rr) >> 1;
            if (ok(mid)) {
                l = mid + 1;
                res = mid;
            } else {
                rr = mid - 1;
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
