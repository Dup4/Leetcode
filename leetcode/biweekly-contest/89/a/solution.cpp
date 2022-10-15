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
    int ans = 0;

    map<string, bool> mp;

    int C(char c) {
        return c - '0';
    }

    bool Done(const string &time) {
        for (const auto &c : time) {
            if (c == '?') {
                return false;
            }
        }

        return true;
    }

    bool OK(const string &time) {
        int h = C(time[0]) * 10 + C(time[1]);
        int m = C(time[3]) * 10 + C(time[4]);

        if (h >= 0 && h <= 23 && m >= 0 && m <= 59) {
            return true;
        }

        return false;
    }

    void DFS(string time) {
        if (mp.count(time)) {
            return;
        }

        mp[time] = true;

        if (Done(time)) {
            ans += OK(time);
            return;
        }

        for (int i = 0; i < 5; i++) {
            if (time[i] == '?') {
                for (int j = 0; j <= 9; j++) {
                    time[i] = char('0' + j);
                    DFS(time);
                }
                return;
            }
        }
    }

    int countTime(string time) {
        ans = 0;
        mp.clear();

        DFS(time);

        return ans;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
