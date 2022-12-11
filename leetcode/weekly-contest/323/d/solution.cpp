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

struct QNode {
    int ix;
    int v;
};

const int N = 1e5 + 10;

struct UFS {
    int fa[N], sze[N];
    void init(int n) {
        memset(fa, -1, sizeof(fa[0]) * (n + 5));

        for (int i = 0; i <= n; i++) {
            sze[i] = 1;
        }
    }

    int find(int x) {
        return fa[x] == -1 ? x : fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);

        if (fx != fy) {
            if (sze[fx] > sze[fy]) {
                swap(fx, fy);
            }

            fa[fx] = fy;
            sze[fy] += sze[fx];

            return true;
        }

        return false;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
} ufs;

int mv[4][2] = {
        {0, -1},
        {0, 1},
        {1, 0},
        {-1, 0},
};

class Solution {
public:
    int n, m;

    int id(int x, int y) {
        return x * m + y;
    }

    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
        int n = int(grid.size());
        int m = int(grid[0].size());
        int q = int(queries.size());

        this->n = n;
        this->m = m;

        int nn = n * m;

        ufs.init(nn + 5);

        auto node = vector<tuple<int, int, int>>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                node.push_back(make_tuple(grid[i][j], i, j));
            }
        }

        sort(all(node));

        auto qq = vector<tuple<int, int>>();
        for (int i = 0; i < q; i++) {
            qq.push_back(make_tuple(queries[i], i));
        }

        sort(all(qq));

        auto res = vector<int>(q, 0);

        for (int i = 0, ix = 0; i < q; i++) {
            const auto [qv, qx] = qq[i];

            while (ix < nn && get<0>(node[ix]) < qv) {
                const auto [v, x, y] = node[ix];

                for (int j = 0; j < 4; j++) {
                    int nx = x + mv[j][0];
                    int ny = y + mv[j][1];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] < qv) {
                        ufs.merge(id(x, y), id(nx, ny));
                    }
                }

                ++ix;
            }

            if (qv > grid[0][0]) {
                res[qx] = ufs.sze[ufs.find(0)];
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
