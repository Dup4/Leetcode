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

const int INF = 0x3f3f3f3f;

// 9 8 7 6 5 4 3 2

// 10 9 1 2 3 4 5 6 7 8

// 7 15 4 14 13 2 6 13
// 7 15 14 6 13
// 7 15 13
// 7 15

// 7 14 4 14 13 2 6 13
// 7 14 14 6 13
// 7 14 14 13
// 7 14 14

class Solution {
public:
    int totalSteps(vector<int> &a) {
        int n = a.size();

        vector<int> dp(n, 0);
        vector<int> st;
        st.push_back(0);

        for (int i = 1; i < n; i++) {
            int cur = 0;
            while (!st.empty() && a[st.back()] <= a[i]) {
                cur = max(cur, dp[st.back()]);
                st.pop_back();
            }

            if (!st.empty()) {
                dp[i] = cur + 1;
            }

            st.push_back(i);
        }

        return *max_element(dp.begin(), dp.end());
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
