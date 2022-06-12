#include <bits/stdc++.h>
#include <algorithm>
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
    int ans;
    int k;

    void dfs(vector<int> &cookies, vector<int> &children, int cur_ans) {
        if (cur_ans >= ans) {
            return;
        }

        if (cookies.empty()) {
            ans = cur_ans;
            return;
        }

        auto c = cookies.back();
        cookies.pop_back();

        for (int i = 0; i < k; i++) {
            children[i] += c;
            dfs(cookies, children, max(cur_ans, children[i]));
            children[i] -= c;
        }

        cookies.push_back(c);
    }

    int distributeCookies(vector<int> &cookies, int k) {
        ans = 0x3f3f3f3f;
        this->k = k;

        auto children = vector<int>(k, 0);

        dfs(cookies, children, 0);

        return ans;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
