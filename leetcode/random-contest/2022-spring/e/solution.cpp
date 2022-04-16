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

const int N = 1e5 + 100;
const int INF = 0x3f3f3f3f;
int n, m;
int f[N];
vector<int> cost;

struct Graph {
    struct E {
        int to, nx;
    } e[N << 2];
    int h[N];
    void init() {
        memset(h, 0, sizeof(h[0]) * (n + 10));
    }

    void addedge(int u, int v) {
        e[++*h] = {v, h[u]};
        h[u] = *h;
    }
} G[2];

#define erp(G, u) for (int o = G.h[u], v = G.e[o].to; o; o = G.e[o].nx, v = G.e[o].to)

struct Tarjan {
    // DFN[i] 点i第一次访问的时间戳
    // Low[i] 点i能访问到的点中的Low的最小值
    // Belong[i] 表示点i在新图中的标号
    // num 表示新图中的点数
    // ptcc[i] 表示第i个点分中的点
    // cut[i]　表示点i是否是割点
    int Low[N], DFN[N], sta[N], num, tot, Belong[N];
    bool cut[N];
    vector<int> ptcc[N];

    void dfs(int u, int pre) {
        Low[u] = DFN[u] = ++*DFN;
        sta[++*sta] = u;
        int pre_cnt = 0, son_cnt = 0;
        erp(G[0], u) {
            if (v == pre && pre_cnt == 0) {
                pre_cnt++;
                continue;
            }
            if (!DFN[v]) {
                ++son_cnt;
                dfs(v, u);
                Low[u] = min(Low[u], Low[v]);
                if (u != pre && Low[v] >= DFN[u])
                    cut[u] = 1;
                if (Low[v] >= DFN[u]) {
                    ++tot;
                    int nv;
                    do {
                        nv = sta[(*sta)--];
                        ptcc[tot].push_back(nv);
                    } while (nv != v);
                    ptcc[tot].push_back(u);
                }
            } else {
                Low[u] = min(Low[u], DFN[v]);
            }
        }

        if (u == pre && son_cnt > 1) {
            cut[u] = 1;
        }
    }

    void gao() {
        memset(DFN, 0, sizeof(DFN[0]) * (n + 10));
        memset(cut, 0, sizeof(cut[0]) * (n + 10));

        tot = 0;
        for (int i = 0; i <= n; ++i) {
            ptcc[i].clear();
        }

        *sta = 0;
        for (int i = 1; i <= n; ++i) {
            if (!DFN[i]) {
                dfs(i, i);
            }
        }
    }

    void gogogo() {
        G[1].init();
        num = tot;

        memset(f, 0x3f, sizeof(f[0]) * (tot + 10));

        //每个割点单独成点
        for (int i = 1; i <= n; ++i) {
            if (cut[i]) {
                Belong[i] = ++num;
                f[num] = cost[i];
            }
        }

        // 每个点双单独成点 点双对应的点向点双里面包含的割点连边
        for (int x = 1; x <= tot; ++x) {
            for (int j = 0, sze = ptcc[x].size(); j < sze; ++j) {
                int y = ptcc[x][j];
                if (cut[y]) {
                    G[1].addedge(x, Belong[y]);
                    G[1].addedge(Belong[y], x);
                } else {
                    Belong[y] = x;
                    f[x] = min(f[x], cost[y]);
                }
            }
        }
    }
} tarjan;

class Solution {
public:
    long long minimumCost(vector<int> &c, vector<vector<int>> &roads) {
        n = c.size();
        m = roads.size();

        G[0].init();

        c.insert(c.begin(), 0);
        cost = c;

        for (auto &r : roads) {
            ++r[0], ++r[1];

            G[0].addedge(r[0], r[1]);
            G[0].addedge(r[1], r[0]);
        }

        tarjan.gao();
        tarjan.gogogo();

        for (int i = 1; i <= tarjan.num; i++) {
            cout << f[i] << " \n"[i == tarjan.num];
        }

        for (int u = 1; u <= tarjan.num; u++) {
            erp(G[1], u) {
                cout << u << " " << v << endl;
            }
        }

        return 1;
    }
};

#ifdef LOCAL

int main() {
    {
        auto s = Solution();
        auto cost = vector<int>({1, 2, 3, 4, 5, 6});
        auto roads = vector<vector<int>>({
                {0, 1},
                {0, 2},
                {1, 3},
                {2, 3},
                {1, 2},
                {2, 4},
                {2, 5},
        });

        s.minimumCost(cost, roads);
    }

    {
        auto s = Solution();
        auto cost = vector<int>({3, 2, 1, 4});
        auto roads = vector<vector<int>>({
                {0, 2},
                {2, 3},
                {3, 1},
        });

        s.minimumCost(cost, roads);
    }

    return 0;
}

#endif
