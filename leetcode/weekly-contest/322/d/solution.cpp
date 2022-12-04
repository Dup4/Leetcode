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
    vector<int> color, node;
    vector<vector<int>> G;
    int n;

    bool dfs(int u, int col) {
        node.push_back(u);
        color[u] = col;
        for (const auto &v : G[u]) {
            if (color[v] != -1) {
                if (color[v] == col) {
                    return false;
                }

                continue;
            }

            if (!dfs(v, col ^ 1)) {
                return false;
            }
        }

        return true;
    }

    int bfs(int st) {
        queue<int> q;
        q.push(st);

        auto dep = vector<int>(n + 5, 0);
        dep[st] = 1;

        int mx_dep = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto &v : G[u]) {
                if (dep[v] == 0) {
                    dep[v] = dep[u] + 1;
                    mx_dep = max(mx_dep, dep[v]);
                    q.push(v);
                }
            }
        }

        return mx_dep;
    }

    int magnificentSets(int n, vector<vector<int>> &edges) {
        this->n = n;

        G = vector<vector<int>>(n + 5, vector<int>());

        for (const auto &e : edges) {
            int u = e[0];
            int v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int res = 0;

        color = vector<int>(n + 5, -1);

        for (int i = 1; i <= n; i++) {
            node.clear();
            if (color[i] == -1) {
                if (!dfs(i, 0)) {
                    return -1;
                }

                int cur_res = 0;

                for (const auto &a : node) {
                    cur_res = max(cur_res, bfs(a));
                }

                res += cur_res;
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
