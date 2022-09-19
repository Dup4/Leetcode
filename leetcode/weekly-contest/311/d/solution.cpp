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

constexpr int N = 1e6 + 10;

struct TRIE {
    struct node {
        int son[26];
        int cnt;
        node() {
            memset(son, -1, sizeof son);
            cnt = 0;
        }
    } t[N];
    int rt, cnt;

    void init() {
        rt = 0;
        t[0] = node();
        cnt = 0;
    }

    void insert(const std::string &s) {
        int cur_rt = rt;
        for (const auto &c : s) {
            if (t[cur_rt].son[c - 'a'] == -1) {
                ++cnt;
                t[cnt] = node();
                t[cur_rt].son[c - 'a'] = cnt;
            }

            cur_rt = t[cur_rt].son[c - 'a'];
            ++t[cur_rt].cnt;
        }
    }

    int query(const std::string &s) {
        int res = 0;
        int cur_rt = rt;
        for (const auto &c : s) {
            cur_rt = t[cur_rt].son[c - 'a'];
            res += t[cur_rt].cnt;
        }

        return res;
    }
} tr;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string> &words) {
        tr.init();

        for (const auto &w : words) {
            tr.insert(w);
        }

        auto res = vector<int>();
        for (const auto &w : words) {
            res.push_back(tr.query(w));
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
