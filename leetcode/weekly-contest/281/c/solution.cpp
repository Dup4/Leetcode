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
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(30, 0), vis(30, 0);
        for (auto &c : s) {
            ++cnt[c - 'a'];
        }

        string res;
        int pre = -1;
        while (true) {
            int f = 0;
            for (int i = 26; i >= 0; i--) {
                if (cnt[i] == 0) {
                    continue;
                }

                if (vis[i] >= repeatLimit) {
                    continue;
                }

                res += char('a' + i);
                ++vis[i];
                f = 1;

                if (pre >= 0 && pre != i) {
                    vis[pre] = 0;
                }

                --cnt[i];
                pre = i;
                break;
            }

            if (f == 0) {
                break;
            }
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
