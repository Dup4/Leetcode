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

const int N = 2e5 + 10, M = 20;
const int INF = 0x3f3f3f3f;

struct Graph {
    struct E {
        int to, nx, w;
    } e[N << 1];
    int h[N], cnt;
    void init(int n) {
        for (int i = 0; i <= n; ++i) h[i] = -1;
        cnt = -1;
    }
    void addedge(int u, int v, int w = 0) {
        e[++cnt] = {v, h[u], w};
        h[u] = cnt;
    }
} G;

struct LCA {
    int fa[N][M], dis[N][M];
    int deep[N];
    void bfs(int rt) {
        queue<int> q;
        deep[rt] = 0;
        fa[rt][0] = rt;
        dis[rt][0] = 0;
        q.emplace(rt);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 1; i < M; ++i) {
                dis[u][i] = dis[u][i - 1] + dis[fa[u][i - 1]][i - 1];
                fa[u][i] = fa[fa[u][i - 1]][i - 1];
            }
            for (int i = G.h[u]; ~i; i = G.e[i].nx) {
                int v = G.e[i].to, w = G.e[i].w;
                if (v == fa[u][0])
                    continue;
                deep[v] = deep[u] + 1;
                fa[v][0] = u;
                dis[v][0] = w;
                q.emplace(v);
            }
        }
    }
    void init(int rt) {
        bfs(rt);
    }
    int querylca(int u, int v) {
        if (deep[u] > deep[v])
            swap(u, v);
        for (int det = deep[v] - deep[u], i = 0; det; det >>= 1, ++i) {
            if (det & 1)
                v = fa[v][i];
        }
        if (u == v)
            return u;
        for (int i = M - 1; i >= 0; --i) {
            if (fa[u][i] == fa[v][i])
                continue;
            u = fa[u][i];
            v = fa[v][i];
        }
        return fa[u][0];
    }
} lca;

class Solution {
public:
    int fa[N], dep[N], sum[N], f[N];
    vector<int> amount;
    vector<int> leaf_node;

    void dfs(int rt, int deep) {
        dep[rt] = deep;
        sum[rt] = amount[rt - 1] + sum[fa[rt]];

        int cnt = 0;

        for (int i = G.h[rt]; ~i; i = G.e[i].nx) {
            int v = G.e[i].to;
            if (v == fa[rt]) {
                continue;
            }

            fa[v] = rt;
            dfs(v, deep + 1);

            ++cnt;
        }

        if (cnt == 0) {
            leaf_node.push_back(rt);
        }
    }

    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount) {
        int n = int(amount.size());
        this->amount = amount;
        leaf_node.clear();
        G.init(n);

        for (int i = 0; i <= n; i++) {
            fa[i] = 0;
            dep[i] = 0;
            sum[i] = 0;
            f[i] = 0;
        }

        ++bob;

        for (const auto &e : edges) {
            int u = e[0];
            int v = e[1];
            ++u, ++v;

            G.addedge(u, v);
            G.addedge(v, u);
        }

        lca.init(1);
        dfs(1, 0);

        {
            int u = bob;
            int base_deep = dep[u];

            vector<int> key_node;

            while (u != 0) {
                key_node.push_back(u);

                int gap = base_deep - dep[u];
                if (dep[u] < gap) {
                    f[u] = amount[u - 1];
                } else if (dep[u] == gap) {
                    f[u] = amount[u - 1] / 2;
                } else {
                    f[u] = 0;
                }

                u = fa[u];
            }

            reverse(all(key_node));

            for (size_t i = 1; i < key_node.size(); i++) {
                f[key_node[i]] += f[key_node[i - 1]];
            }
        }

        int res = -INF;
        for (const auto &u : leaf_node) {
            int _lca = lca.querylca(u, bob);
            int cur_sum = 0;
            cur_sum += sum[u] - sum[_lca] + f[_lca];
            res = max(res, cur_sum);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
