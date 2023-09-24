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

const int N = 1e5 + 20;
int pri[N], check[N];
void sieve() {
    memset(check, 0, sizeof check);
    check[1] = 1;
    *pri = 0;
    for (int i = 2; i < N; ++i) {
        if (!check[i]) {
            pri[++*pri] = i;
        }
        for (int j = 1; j <= *pri; ++j) {
            if (1ll * i * pri[j] >= N)
                break;
            check[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}

class Solution {
public:
    void dfs(int u, int fa) {
        if (!check[u]) {
            f[u][0] = 0;
            f[u][1] = 1;
        } else {
            f[u][0] = 1;
            f[u][1] = 0;
        }

        for (const auto &v : G[u]) {
            if (v == fa) {
                continue;
            }

            dfs(v, u);

            if (!check[u]) {
                f[u][1] += f[v][0];
            } else {
                f[u][0] += f[v][0];
                f[u][1] += f[v][1];
            }
        }
    }

    void dfs1(int u, int fa) {
        // if (!check[u]) {
        //     g[u][0] += 0;
        //     g[u][1] += 1;
        // } else {
        //     g[u][0] += 1;
        //     g[u][1] += 0;
        // }

        for (const auto &v : G[u]) {
            if (v == fa) {
                continue;
            }

            if (!check[v]) {
                g[v][1] += g[u][0] + f[u][0] - f[v][0];
            } else {
                g[v][0] += g[u][0] + f[u][0] - f[v][0];
                g[v][1] += g[u][1] + f[u][1] - f[v][1];
            }

            dfs1(v, u);
        }
    }

    long long countPaths(int n, vector<vector<int>> &edges) {
        this->n = n;
        clear();

        if (n == 1) {
            return 0;
        }

        for (const auto &e : edges) {
            int u = e[0];
            int v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs(1, 0);

        // g[1][0] = 1;
        dfs1(1, 0);

        for (int i = 1; i <= n; i++) {
            res += f[i][1];
            res += g[i][1];

            // cout << i << " " << f[i][0] << " " << f[i][1] << " " << g[i][0] << " " << g[i][1] << endl;
        }

        res /= 2;

        for (int i = 2; i <= n; i++) {
            if (!check[i]) {
                --res;
            }
        }

        return res;
    }

private:
    void clear() {
        if (!load_sieve) {
            sieve();
            load_sieve = true;
        }

        for (int i = 0; i <= n + 5; i++) {
            f[i][0] = 0;
            f[i][1] = 0;

            g[i][0] = 0;
            g[i][1] = 0;
        }

        res = 0;
        G = vector<vector<int>>(n + 5, vector<int>());
    }

    int n;
    vector<vector<int>> G;
    ll res, f[N][2], g[N][2];

    bool load_sieve{false};
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
