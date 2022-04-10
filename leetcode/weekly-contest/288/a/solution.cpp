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
    int largestInteger(int num) {
        vector<vector<int>> f(2, vector<int>());
        auto g = vector<int>();

        int x = num;
        while (x) {
            int y = x % 10;
            f[y % 2].push_back(y);
            x /= 10;
            g.push_back(y % 2);
        }

        sort(all(f[0]));
        sort(all(f[1]));

        reverse(all(f[0]));
        reverse(all(f[1]));

        ll res = 0;
        ll base = 1;
        for (auto &_g : g) {
            res += base * f[_g].back();
            f[_g].pop_back();
            base *= 10;
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
