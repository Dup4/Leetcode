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
    ll calc(int x) {
        return 1ll * x * (x - 1) / 2;
    }

    long long countGood(vector<int> &nums, int k) {
        int n = int(nums.size());

        auto mp = map<int, int>();
        ll res = 0;
        ll tot = 0;
        int l = -1;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            tot -= calc(mp[x]);
            ++mp[x];
            tot += calc(mp[x]);

            while (l < i) {
                int y = nums[l + 1];
                ll _tot = tot;
                _tot -= calc(mp[y]);
                _tot += calc(mp[y] - 1);

                if (_tot >= k) {
                    ++l;
                    --mp[y];
                    tot = _tot;
                } else {
                    break;
                }
            }

            if (tot >= k) {
                res += (l + 2);
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
