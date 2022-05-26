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

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
ll res;

struct Cartesian_Tree {
    struct node {
        int id, val, fa;
        int son[2];
        node() {}
        node(int id, int val, int fa) : id(id), val(val), fa(fa) {
            son[0] = son[1] = 0;
        }
        bool operator<(const node &other) const {
            return val < other.val;
        }
    } t[N];
    int root;

    void init() {
        t[0] = node(0, -INF, 0);
    }

    void build(int n, const vector<int> &a) {
        for (int i = 1; i <= n; ++i) {
            t[i] = node(i, a[i], 0);
        }

        for (int i = 1; i <= n; ++i) {
            int k = i - 1;
            while (t[i] < t[k]) {
                k = t[k].fa;
            }

            t[i].son[0] = t[k].son[1];

            t[k].son[1] = i;

            t[i].fa = k;

            t[t[i].son[0]].fa = i;
        }
        root = t[0].son[1];
    }

    pair<ll, int> DFS(int u) {
        if (!u) {
            return make_pair(0, 0);
        }

        auto l = DFS(t[u].son[0]);
        auto r = DFS(t[u].son[1]);

        ll sum = (l.fi + r.fi + t[u].val) % mod;
        int sze = l.se + r.se + 1;

        res +=

                return make_pair(sum, sze);
    }

    void print(int u) {
        if (!u)
            return;
        print(t[u].son[0]);
        printf("%d %d\n", t[u].id, t[u].val);
        print(t[u].son[1]);
    }
} CT;

class Solution {
public:
    int totalStrength(vector<int> &a) {
        int n = a.size();
        a.insert(a.begin(), 0);
        res = 0;
        CT.build(n, a);
        CT.DFS(CT.root);
        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
