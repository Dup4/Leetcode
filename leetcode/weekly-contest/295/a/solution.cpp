#include <bits/stdc++.h>
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

// solution class

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<char> need(30, 0), has(30, 0);

        for (const char &c : target) {
            ++need[c - 'a'];
        }

        for (const char &c : s) {
            ++has[c - 'a'];
        }

        int res = INF;

        for (int i = 0; i < 26; i++) {
            if (need[i] == 0) {
                continue;
            }

            if (need[i] > has[i]) {
                return 0;
            }

            res = min(res, has[i] / need[i]);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
