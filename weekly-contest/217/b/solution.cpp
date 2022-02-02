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

class Solution {
public:
    vector<int> mostCompetitive(vector<int> &nums, int k) {
        int n = nums.size();
        set<PII> se;
        int ix = n - k, jx = -1;
        vector<int> res;
        for (int i = 0; i < n - k; ++i) se.insert(PII(nums[i], i));
        for (int i = n - k; i < n; ++i) {
            se.insert(PII(nums[i], i));
            while (1) {
                auto it = *se.begin();
                se.erase(it);
                if (it.se <= jx)
                    continue;
                res.push_back(it.fi);
                jx = it.se;
                break;
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
