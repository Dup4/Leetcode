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
    int shortestSequence(vector<int> &rolls, int k) {
        int res = 0;
        auto f = vector<int>(k + 1, 0);
        int cnt = 0;
        for (const auto &r : rolls) {
            if (f[r] == 0) {
                ++cnt;
                f[r] = 1;
                if (cnt == k) {
                    ++res;
                    cnt = 0;
                    auto g = vector<int>(k + 1, 0);
                    f.swap(g);
                }
            }
        }

        return res + 1;
    }
};

#ifdef LOCAL

int main() {
    auto s = Solution();

    {
        auto r = vector<int>({4, 2, 1, 2, 3, 3, 2, 4, 1});
        dbg(s.shortestSequence(r, 4));
    }

    {
        auto r = vector<int>({1, 1, 2, 2});
        dbg(s.shortestSequence(r, 2));
    }

    {
        auto r = vector<int>({1, 1, 3, 2, 2, 2, 3, 3});
        dbg(s.shortestSequence(r, 4));
    }

    {
        auto r = vector<int>({1, 1});
        dbg(s.shortestSequence(r, 2));
    }

    return 0;
}

#endif
