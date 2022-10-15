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
    vector<vector<int>> G;
    vector<int> nums;
    int n, sum, target;
    int cnt;

    int DFS(int u, int fa) {
        int cur = nums[u];
        for (const auto &v : G[u]) {
            if (v == fa) {
                continue;
            }

            cur += DFS(v, u);
        }

        if (cur == target) {
            ++cnt;
            cur = 0;
        }

        return cur;
    }

    bool OK(int m) {
        target = sum / m;
        cnt = 0;
        DFS(0, 0);

        return cnt == m;
    }

    int componentValue(vector<int> &nums, vector<vector<int>> &edges) {
        n = int(nums.size());
        G = vector<vector<int>>(n + 1, vector<int>());
        this->nums = nums;

        for (const auto &e : edges) {
            int u = e[0];
            int v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        sum = accumulate(all(nums), 0);

        for (int i = min(n, sum); i >= 1; i--) {
            if (sum % i != 0) {
                continue;
            }

            if (OK(i)) {
                return i - 1;
            }
        }

        return 0;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
