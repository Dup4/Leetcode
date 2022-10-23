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

// 6 8 12
// 2 10 14
// 4 -2 -2
// 1 2 5
// 1 3 4
// 1 5 2
// 1 3 4
// 0 -2 2

class Solution {
public:
    long long makeSimilar(vector<int> &nums, vector<int> &target) {
        int n = int(nums.size());

        auto a = vector<vector<int>>(2, vector<int>());
        auto b = vector<vector<int>>(2, vector<int>());

        for (int i = 0; i < n; i++) {
            a[nums[i] % 2].push_back(nums[i]);
            b[target[i] % 2].push_back(target[i]);
        }

        for (int i = 0; i < 2; i++) {
            sort(all(a[i]));
            sort(all(b[i]));
        }

        ll res = 0;
        for (int i = 0; i < 2; i++) {
            int m = int(a[i].size());
            for (int j = 0; j < m; j++) {
                res += abs(a[i][j] - b[i][j]) / 2;
            }
        }

        res /= 2;

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
