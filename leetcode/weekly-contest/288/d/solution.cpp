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

        int cnt = 0;
        ll sum = 0;
        ll res_p = 0;
        ll target_need = 1ll * n * target - accumulate(all(fl), 0ll);

        for (int i = 0, j = 0, k = 0; i < target; i++) {
            while (j < n && fl[j] <= i) {
                ++cnt;
                sum += fl[j];
                ++j;
            }

            ll remind = has - (1ll * i * cnt - sum);

            while (k < n && (remind < target_need || k < cnt)) {
                target_need -= target - fl[k];
                k++;
            }

            remind -= target_need;

            if (remind < 0) {
                continue;
            }

            ll cur = 0;
            cur += 1ll * partial * i * (cnt > 0);
            cur += 1ll * full * (n - k);
            cur += 1ll * full * max<ll>(0, min<ll>(cnt - 1, remind / (target - i)));

            res_p = max(res_p, cur);
        }

        return res + res_p;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
