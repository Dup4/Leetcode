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
    bool isItPossible(string word1, string word2) {
        auto diff = vector<int>(5, 0);
        auto cnt = vector<vector<int>>(2, vector<int>(50, 0));
        auto words = vector<string>({word1, word2});

        for (int i = 0; i < 2; i++) {
            const auto &w = words[i];
            for (const auto &c : w) {
                ++cnt[i][c - 'a'];
                if (cnt[i][c - 'a'] == 1) {
                    ++diff[i];
                }
            }
        }

        if (diff[0] < diff[1]) {
            swap(diff[0], diff[1]);
            swap(cnt[0], cnt[1]);
        }

        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                if (cnt[0][i] == 0 || cnt[1][j] == 0) {
                    continue;
                }

                auto diff_ = diff;

                if (cnt[0][i] == 1) {
                    --diff_[0];
                }

                --cnt[0][i];

                if (cnt[0][j] == 0) {
                    ++diff_[0];
                }
                ++cnt[0][j];

                if (cnt[1][i] == 0) {
                    ++diff_[1];
                }

                ++cnt[1][i];

                if (cnt[1][j] == 1) {
                    --diff_[1];
                }
                --cnt[1][j];

                if (diff_[0] == diff_[1]) {
                    return true;
                }

                ++cnt[0][i];
                --cnt[0][j];
                --cnt[1][i];
                ++cnt[1][j];
            }
        }

        return false;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
