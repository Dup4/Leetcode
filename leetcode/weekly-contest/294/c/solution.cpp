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
    int minimumLines(vector<vector<int>> &s) {
        int n = s.size();

        if (n == 1) {
            return 0;
        }

        if (n <= 2) {
            return 1;
        }

        sort(s.begin(), s.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        const auto ok = [](vector<int> a, vector<int> b, vector<int> c) {
            ll aa = 1ll * (b[1] - a[1]) * (c[0] - a[0]);
            ll bb = 1ll * (b[0] - a[0]) * (c[1] - a[1]);

            return aa == bb;
        };

        int res = 1;
        int l = 0;
        for (int i = 2; i < n; i++) {
            if (ok(s[l], s[l + 1], s[i])) {
                continue;
            }

            l = i - 1;
            ++res;
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
