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

// ababd
// abdab
// abdba

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int res = 0;

        vector<int> cnt(30, 0), use(30, 0);
        for (const auto &c : s) {
            ++cnt[c - 'a'];
        }

        int n = s.size();
        int mid = n / 2;

        auto valid = [&](int c) {
            return use[c] < cnt[c] / 2;
        };

        auto _swap = [&](int i, int j) {
            for (int k = j; k > i; k--) {
                swap(s[k], s[k - 1]);
                ++res;
            }
        };

        for (int i = 0; i < mid; i++) {
            for (int j = i; j < n; j++) {
                if (valid(s[j] - 'a')) {
                    _swap(i, j);
                    break;
                }
            }

            ++use[s[i] - 'a'];
        }

        if (n & 1) {
            int target = 0;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] & 1) {
                    target = i;
                    break;
                }
            }

            for (int i = mid; i < n; i++) {
                if (s[i] - 'a' == target) {
                    _swap(mid, i);
                    break;
                }
            }
        }

        for (int i = (n & 1) ? mid + 1 : mid; i < n; i++) {
            int u = s[i], v = s[n - i - 1];
            if (u == v) {
                continue;
            }

            for (int j = i; j < n; j++) {
                if (s[j] == v) {
                    _swap(i, j);
                    break;
                }
            }
        }

        // dbg(s);

        return res;
    }
};

#ifdef LOCAL

int main() {
    {
        auto s = new Solution();
        auto ans = s->minMovesToMakePalindrome("aabb");
        dbg(ans);
    }
    return 0;
}

#endif
