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
    string categorizeBox(int l, int w, int h, int mass) {
        const int E2 = 1e2;
        const int E4 = 1e4;
        const int E9 = 1e9;

        ll v = 1ll * l * w * h;

        bool b = (l >= E4 || w >= E4 || h >= E4 || v >= E9);
        bool e = (mass >= E2);

        if (b && e) {
            return "Both";
        }

        if (!b && !e) {
            return "Neither";
        }

        if (b) {
            return "Bulky";
        }

        if (e) {
            return "Heavy";
        }

        return "";
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
