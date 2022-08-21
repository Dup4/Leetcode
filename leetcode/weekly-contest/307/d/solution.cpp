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

struct node {
    ll sum;
    int ix;

    node(ll sum, int ix) : sum(sum), ix(ix) {}

    bool operator<(const node &other) const {
        return sum < other.sum;
    }
};

class Solution {
public:
    long long kSum(vector<int> &nums, int k) {
        int n = int(nums.size());

        ll sum = 0;
        for (auto &a : nums) {
            if (a >= 0) {
                sum += a;
            } else {
                a = -a;
            }
        }

        sort(nums.begin(), nums.end());

        priority_queue<node> pq;
        pq.push(node(sum - nums[0], 0));

        ll res = sum;
        --k;

        while (k--) {
            auto tp = pq.top();
            pq.pop();

            ll sum = tp.sum;
            int ix = tp.ix;

            res = sum;

            if (ix + 1 < n) {
                pq.push(node(sum - nums[ix + 1] + nums[ix], ix + 1));
                pq.push(node(sum - nums[ix + 1], ix + 1));
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
