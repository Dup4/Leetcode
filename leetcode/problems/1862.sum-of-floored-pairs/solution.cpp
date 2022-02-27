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
    int sumOfFlooredPairs(vector<int> &nums) {
        static const int mod = 1e9 + 7;
        const int N = *max_element(nums.begin(), nums.end());

        vector<int> cnt(N + 10, 0), sum(N + 10, 0);
        for (const auto &v : nums) {
            ++cnt[v];
        }

        for (int i = 1; i <= N; i++) {
            sum[i] = sum[i - 1] + cnt[i];
        }

        int res = 0;
        for (int i = 1; i <= N; i++) {
            if (cnt[i] == 0) {
                continue;
            }

            int cur_res = 0;
            for (int d = 1; i * d <= N; d++) {
                int up = min(N + 1, i * (d + 1));
                int down = i * d;
                cur_res += 1ll * (sum[up - 1] - sum[down - 1]) * d % mod;
                if (cur_res >= mod) {
                    cur_res -= mod;
                }
            }

            res += 1ll * cnt[i] * cur_res % mod;
            if (res >= mod) {
                res -= mod;
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
