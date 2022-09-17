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
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int res = 0;

        auto mon = vector<int>({0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
        auto mp = map<pair<int, int>, int>();

        auto g = [](char c) {
            return c - '0';
        };

        auto f = [&g, &mp, &mon](const std::string &st_str, const std::string &ed_str) {
            auto st = make_pair(g(st_str[0]) * 10 + g(st_str[1]), g(st_str[3]) * 10 + g(st_str[4]));
            auto ed = make_pair(g(ed_str[0]) * 10 + g(ed_str[1]), g(ed_str[3]) * 10 + g(ed_str[4]));

            while (true) {
                mp[st] += 1;
                if (st == ed) {
                    break;
                }

                ++st.second;
                if (st.second > mon[st.first]) {
                    ++st.first;
                    st.second = 1;
                }
            }
        };

        f(arriveAlice, leaveAlice);
        f(arriveBob, leaveBob);

        for (const auto &[k, v] : mp) {
            if (v == 2) {
                ++res;
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
