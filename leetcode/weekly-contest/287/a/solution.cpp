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
    int convertTime(string current, string correct) {
        auto f = [](string s) {
            int res = 0;
            int a = (s[0] - '0') * 10 + (s[1] - '0');
            int b = (s[3] - '0') * 10 + (s[4] - '0');
            return a * 60 + b;
        };

        int a = f(current);
        int b = f(correct);
        int res = 0;
        int gap = b - a;

        res += gap / 60;
        gap %= 60;
        res += gap / 15;
        gap %= 15;
        res += gap / 5;
        gap %= 5;
        res += gap;
        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
