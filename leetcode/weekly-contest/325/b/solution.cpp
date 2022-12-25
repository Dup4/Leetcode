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
    int takeCharacters(string s, int k) {
        int n = int(s.size());

        auto cnt = vector<int>(3, 0);
        for (const auto &c : s) {
            ++cnt[c - 'a'];
        }

        if (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
            return -1;
        }

        int r = 0;
        while (r < n) {
            if (cnt[s[r] - 'a'] > k) {
                --cnt[s[r] - 'a'];
                ++r;
            } else {
                break;
            }
        }

        int res = n - r;

        for (int i = 0; i < n; i++) {
            while (r <= i) {
                --cnt[s[r] - 'a'];
                ++r;
            }

            ++cnt[s[i] - 'a'];

            while (r < n) {
                if (cnt[s[r] - 'a'] > k) {
                    --cnt[s[r] - 'a'];
                    ++r;
                } else {
                    break;
                }
            }

            res = min(res, i + 1 + n - r);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
