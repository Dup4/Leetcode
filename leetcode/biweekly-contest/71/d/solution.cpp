#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define rall rbegin(a), rend(a)
#define lowbit(x) ((x) & (-(x)))
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

const ll INF = 0x3f3f3f3f3f3f3f3f;

class Solution {
public:
    long long minimumDifference(vector<int> &nums) {
        ll res = INF;
        int n = nums.size() / 3;

        vector<ll> lsum(n * 3, 0), rsum(n * 3, 0);

        {
            ll sum = 0;
            multiset<int> s;
            for (int i = 0; i <= n - 1; i++) {
                sum += nums[i];
                s.insert(nums[i]);
            }

            lsum[n - 1] = sum;
            for (int i = n; i < n * 2; i++) {
                int a = nums[i];
                s.insert(a);
                sum += a;
                sum -= *(s.rbegin());
                lsum[i] = sum;
                s.erase(s.find(*(s.rbegin())));
            }
        }

        {
            ll sum = 0;
            multiset<int> s;
            for (int i = n * 3 - 1; i >= n * 2; i--) {
                sum += nums[i];
                s.insert(nums[i]);
            }

            rsum[n * 2] = sum;
            for (int i = n * 2 - 1; i >= n; i--) {
                int a = nums[i];
                s.insert(a);
                sum += a;
                sum -= *(s.begin());
                rsum[i] = sum;
                s.erase(s.find(*(s.begin())));
            }
        }

        dbg(lsum, rsum);

        for (int i = n - 1; i < n * 2; i++) {
            chmin(res, lsum[i] - rsum[i + 1]);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    auto s = new Solution();

    {
        auto vec = vector<int>({3, 1, 2});
        auto ans = s->minimumDifference(vec);
        assert_eq(ans, ll(-1));
    }

    {
        auto vec = vector<int>({7, 9, 5, 8, 1, 3});
        auto ans = s->minimumDifference(vec);
        assert_eq(ans, ll(1));
    }
    return 0;
}

#endif
