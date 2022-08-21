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
    vector<long long> maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries) {
        int n = int(nums.size());

        auto f = vector<ll>(n + 5, 0);
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] + nums[i - 1];
        }

        auto se = set<pair<int, int>>();
        auto sum_se = multiset<ll>();

        se.insert({1, n});
        sum_se.insert(f[n]);

        auto res = vector<ll>();
        for (auto ix : removeQueries) {
            ++ix;

            auto it = se.lower_bound({ix, n + 1});
            --it;

            // if (it == se.end()) {
            //     cout << ix << " " << se.size() << endl;
            //     continue;
            // }

            auto st = it->first;
            auto ed = it->second;

            sum_se.erase(sum_se.lower_bound(f[ed] - f[st - 1]));

            {
                auto _ed = ix - 1;
                if (st <= _ed) {
                    se.insert({st, _ed});
                    sum_se.insert(f[_ed] - f[st - 1]);
                }
            }

            {
                auto _st = ix + 1;
                if (_st <= ed) {
                    se.insert({_st, ed});
                    sum_se.insert(f[ed] - f[_st - 1]);
                }
            }

            se.erase(it);
            if (sum_se.empty()) {
                res.push_back(0);
            } else {
                res.push_back(*sum_se.rbegin());
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
