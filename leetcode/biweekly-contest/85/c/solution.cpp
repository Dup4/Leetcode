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

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts) {
        int n = int(s.length());
        auto f = vector<int>(n + 5, 0);
        for (const auto &s : shifts) {
            int st = s[0];
            int ed = s[1];
            int d = s[2];
            if (d == 0) {
                d = -1;
            }

            f[st + 1] += d;
            f[ed + 2] -= d;
        }

        for (int i = 1; i <= n; i++) {
            f[i] += f[i - 1];
            f[i] = (f[i] % 26 + 26) % 26;
        }

        for (int i = 0; i < n; i++) {
            s[i] -= 'a';
            s[i] = char((s[i] + f[i + 1] % 26 + 26) % 26);
            s[i] += 'a';
        }

        return s;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
