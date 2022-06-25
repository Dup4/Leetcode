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

constexpr int N = 1e5 + 10;

struct UFS {
    int fa[N], rk[N], sz[N];
    void init(int n) {
        memset(fa, 0, sizeof(fa[0]) * (n + 5));
        memset(rk, 0, sizeof(rk[0]) * (n + 5));
        for (int i = 1; i <= n; i++) {
            sz[i] = 1;
        }
    }
    int find(int x) {
        return fa[x] == 0 ? x : fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            if (rk[fx] > rk[fy])
                swap(fx, fy);
            fa[fx] = fy;
            if (rk[fx] == rk[fy])
                ++rk[fy];
            sz[fy] += sz[fx];
            return true;
        }
        return false;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
} ufs;

class Solution {
public:
    long long countPairs(int n, vector<vector<int>> &edges) {
        ufs.init(n);

        for (auto &e : edges) {
            ufs.merge(e[0] + 1, e[1] + 1);
        }

        auto f = vector<int>();

        for (int i = 1; i <= n; i++) {
            if (ufs.find(i) == i) {
                f.push_back(ufs.sz[i]);
            }
        }

        ll sum = f[0];
        ll res = 0;
        for (size_t i = 1; i < f.size(); i++) {
            res += f[i] * sum;
            sum += f[i];
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
