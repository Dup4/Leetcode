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
    string largestNumber(vector<int> &nums) {
        sort(all(nums), [&](const int a, const int b) -> bool {
            int f = 0;

            auto _a = to_string(a);
            auto _b = to_string(b);

            return (_a + _b) > (_b + _a);
        });

        string res = "";
        for (const auto &a : nums) {
            res += to_string(a);
        }

        int zero = 0;
        for (const char &c : res) {
            if (c == '0') {
                ++zero;
            }
        }

        if (zero == res.size()) {
            return "0";
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
