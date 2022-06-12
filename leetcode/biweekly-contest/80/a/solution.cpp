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
    bool strongPasswordCheckerII(string s) {
        int l = s.length();
        if (l < 8) {
            return false;
        }

        bool a = 0, b = 0, c = 0, d = 0;

        for (int i = 0; i < l; i++) {
            if (i + 1 < l && s[i] == s[i + 1]) {
                return false;
            }

            if (s[i] >= 'a' && s[i] <= 'z') {
                a = 1;
            }

            if (s[i] >= 'A' && s[i] <= 'Z') {
                b = 1;
            }

            if (s[i] >= '0' && s[i] <= '9') {
                c = 1;
            }

            if (string("!@#$%^&*()-+").find(s[i]) != string::npos) {
                d = 1;
            }
        }

        return a && b && c && d;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
