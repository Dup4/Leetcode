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

const int N = 1e5 + 5;

class Solution {
public:
    long long maximumBeauty(vector<int> &fl, long long has, int target, int full, int partial) {
        ll res = 0;

        sort(all(fl));

        while (!fl.empty()) {
            if (fl.back() >= target) {
                res += full;
                fl.pop_back();
            } else {
                break;
            }
        }

        int n = fl.size();

        if (n == 0) {
            return res;
        }

        auto cnt = vector<int>(target + 1, 0);
        auto sum = vector<ll>(target + 1, 0);
        auto remind = vector<ll>(n + 1, 0);

        for (auto &_fl : fl) {
            ++cnt[_fl];
            sum[_fl] += _fl;
        }

        for (int i = 1; i <= target; i++) {
            cnt[i] += cnt[i - 1];
            sum[i] += sum[i - 1];
        }

        for (int i = n - 1, j = 1; i >= 0; i--, j++) {
            remind[j] = remind[j - 1] + (target - fl[i]);
        }

        ll resP = 0;
        int ix = n;
        for (int i = 1; i <= target; i++) {
            int tot_cnt = cnt[i];
            ll has_sum = sum[i];

            ll need = 1ll * i * tot_cnt - has_sum;

            if (i == target) {
                need = 0;
                ix = n;
            }

            if (need > has) {
                continue;
            }

            ll cur = 0;
            ll _has = has - need;

            if (i == target) {
                while (ix > 0 && remind[ix] > _has) {
                    --ix;
                }
            } else {
                while (ix > 0 && (ix > n - tot_cnt || remind[ix] > _has)) {
                    --ix;
                }
            }

            if (i == target) {
                cur = 1ll * full * ix;
            } else {
                cur = 1ll * i * partial +
                      1ll * full * min(ll(n - 1), (ix + ((_has - remind[ix]) / max(1, (target - i)))));
            }

            resP = max(resP, cur);
        }

        return res + resP;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
