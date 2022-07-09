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

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int th, res;

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

    void build(vector<int> &a) {
        int n = int(a.size());
        for (int i = 1; i <= n; ++i) {
            t[i] = node(i, a[i - 1], 0);
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
    int DFS(int u) {
        if (!u)
            return 0;

        int sze = DFS(t[u].son[0]) + DFS(t[u].son[1]) + 1;
        if (t[u].val > th / sze) {
            res = sze;
        }

        return sze;
    }
} CT;

class Solution {
public:
    int validSubarraySize(vector<int> &nums, int threshold) {
        CT.init();
        CT.build(nums);
        res = -1;
        th = threshold;
        CT.DFS(CT.root);

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
