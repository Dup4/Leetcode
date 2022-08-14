#include <bits/stdc++.h>
#include <cstring>
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
// #include <debug.hpp>
#else
#define dbg(...)
#endif
// head

class Solution {
public:
    int dp[20][2][2][2050];
    bool init{false};

    int dfs(int pos, int up, int pre_zero, int flag, vector<int> x) {
        if (pos == 0) {
            return !pre_zero;
        }

        int &res = dp[pos][up][pre_zero][flag];
        if (res != -1) {
            return res;
        }

        res = 0;

        int current_up = x.back();
        auto _x = x;
        _x.pop_back();

        for (int i = 0; i <= 9; i++) {
            if (up && i > current_up) {
                break;
            }

            int _flag = flag;
            if (pre_zero && i == 0) {
            } else {
                _flag |= (1 << i);
                if (_flag == flag) {
                    continue;
                }
            }

            res += dfs(pos - 1, up && current_up == i, pre_zero && i == 0, _flag, _x);
        }

        return res;
    }

    int countSpecialNumbers(int n) {
        if (!init) {
            memset(dp, -1, sizeof dp);
            init = true;
        }

        auto f = [](int x) {
            int res = 0;
            while (x) {
                ++res;
                x /= 10;
            }
            return res;
        };

        auto g = [](int x) {
            auto f = vector<int>();
            while (x) {
                f.push_back(x % 10);
                x /= 10;
            }
            return f;
        };

        return dfs(f(n), 1, 1, 0, g(n));
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
