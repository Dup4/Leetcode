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

const int ALP = 26;
const int N = 1e5 + 10;

struct SQAM {
    struct node {
        int nx[ALP];
        void init() {
            memset(nx, 0, sizeof nx);
        }
    } t[N];
    int lst[ALP], pre[N], tot;

    void init() {
        tot = 1;
        t[1].init();
        for (int i = 0; i < ALP; ++i) lst[i] = 1;
    }

    void extend(int c) {
        int cur = ++tot;
        t[cur].init();
        pre[cur] = lst[c];
        for (int i = tot - 1; i >= pre[cur]; --i) t[i].nx[c] = cur;
        lst[c] = cur;
    }
} sqam;

class Solution {
public:
    int appendCharacters(string s, string t) {
        sqam.init();
        for (const char &c : s) {
            sqam.extend(c - 'a');
        }

        int cur = 1;
        int n = int(t.size());

        for (int i = 0; i < n; i++) {
            int c = t[i] - 'a';
            if (sqam.t[cur].nx[c]) {
                cur = sqam.t[cur].nx[c];
            } else {
                return n - i;
            }
        }

        return 0;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
