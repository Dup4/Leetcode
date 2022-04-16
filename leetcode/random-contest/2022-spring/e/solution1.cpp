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

const int N = 1e5 + 10;
int n, m;

struct Edge {
    int v, nx, cut;
} e[N << 1];

int h[N], tot;
inline void addedge(int u, int v) {
    e[tot] = {v, h[u], 0};
    h[u] = tot++;
}

struct Tarjan {
    int Low[N], DFN[N], add_block[N], cut[N], bridge;
    bool Insta[N];
    void dfs(int u, int pre) {
        Low[u] = DFN[u] = ++*Low;
        Insta[u] = 1;
        int son = 0;
        int pre_cnt = 0;
        for (int i = h[u]; ~i; i = e[i].nx) {
            int v = e[i].v;
            if (v == pre && pre_cnt == 0) {
                pre_cnt++;
                continue;
            }
            if (!DFN[v]) {
                ++son;
                dfs(v, u);
                Low[u] = min(Low[u], Low[v]);
                if (Low[v] > DFN[u]) {
                    ++bridge;
                    e[i].cut = 1;
                    e[i ^ 1].cut = 1;
                }
                if (u != pre && Low[v] >= DFN[u]) {
                    cut[u] = 1;
                    ++add_block[u];
                }
            } else
                Low[u] = min(Low[u], DFN[v]);
        }
        if (u == pre && son > 1)
            cut[u] = 1;
        if (u == pre)
            add_block[u] = son - 1;
        Insta[u] = 0;
    }

    void gao(int n) {
        memset(DFN, 0, sizeof(DFN[0]) * (n + 10));
        memset(Insta, 0, sizeof(Insta[0]) * (n + 10));
        *Low = 0;
        for (int i = 1; i <= n; ++i) {
            if (!DFN[i]) {
                dfs(i, i);
            }
        }
    }

    void gogogo() {
        vector<int> vec;
        for (int i = 1; i <= n; ++i) {
            if (cut[i]) {
                vec.push_back(i);
            }
        }

        int sze = vec.size();

        printf("%d\n", sze);
        for (int i = 0; i < sze; ++i) {
            printf("%d%c", vec[i], " \n"[i == sze - 1]);
        }
    }
} tarjan;

class Solution {
public:
    long long minimumCost(vector<int> &cost, vector<vector<int>> &roads) {
        n = cost.size();

        tot = 0;
        memset(h, -1, sizeof(h[0]) * (n + 10));

        for (auto &r : roads) {
            ++r[0], ++r[1];

            addedge(r[0], r[1]);
            addedge(r[1], r[0]);
        }

        tarjan.gao(n);
        tarjan.gogogo();

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
