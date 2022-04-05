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
    string largestMultipleOfThree(vector<int> &digits) {
        auto f = vector<vector<int>>(3, vector<int>());
        for (auto &d : digits) {
            f[d % 3].push_back(d);
        }

        for (int i = 0; i < 3; i++) {
            sort(all(f[i]), greater<int>());
        }

        {
            int x = f[1].size();
            int y = f[2].size();
            int tot = (x + y * 2) % 3;

            if (tot == 1) {
                if (x) {
                    f[1].pop_back();

                } else {
                    f[2].pop_back();
                    f[2].pop_back();
                }
            }

            if (tot == 2) {
                if (y) {
                    f[2].pop_back();
                } else {
                    f[1].pop_back();
                    f[1].pop_back();
                }
            }
        }

        auto ff = vector<int>();
        for (int i = 0; i < 3; i++) {
            ff.insert(ff.begin(), all(f[i]));
        }

        sort(all(ff), greater<int>());

        string res = "";

        for (auto &a : ff) {
            res += to_string(a);
        }

        if (res == "") {
            return res;
        }

        int zero = 0;
        for (auto &c : res) {
            if (c == '0') {
                ++zero;
            } else {
                break;
            }
        }

        if (zero == res.size()) {
            return res.substr(zero - 1);
        }

        return res.substr(zero);
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
