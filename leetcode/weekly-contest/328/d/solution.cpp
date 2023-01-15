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

struct Node {
    ll mx{0};
    ll mx_without_endpoint{0};
};

class Solution {
public:
    vector<int> price;
    vector<Node> node_vec;
    vector<vector<int>> G;
    ll res;

    void dfs(int u, int fa) {
        auto tmp = vector<Node>();

        for (const auto &v : G[u]) {
            if (v == fa) {
                continue;
            }

            dfs(v, u);
            tmp.push_back(node_vec[v]);
        }

        int p = price[u];
        auto &u_node = node_vec[u];
        ll mx_mx = 0;
        ll mx_mx_without_endpoint = -0x3f3f3f3f3f3f3f3f;

        u_node.mx = p;
        for (const auto &node : tmp) {
            res = max(res, mx_mx);
            res = max(res, mx_mx_without_endpoint + p);
            res = max(res, mx_mx + node.mx_without_endpoint + p);
            res = max(res, mx_mx_without_endpoint + node.mx + p);

            mx_mx = max(mx_mx, node.mx);
            mx_mx_without_endpoint = max(mx_mx_without_endpoint, node.mx_without_endpoint);

            u_node.mx = max(u_node.mx, node.mx + p);
            u_node.mx_without_endpoint = max(u_node.mx_without_endpoint, node.mx_without_endpoint + p);
        }

        res = max(res, mx_mx);
        res = max(res, mx_mx_without_endpoint + p);
    }

    long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price) {
        G = vector<vector<int>>(n + 1, vector<int>());
        this->price = price;
        node_vec = vector<Node>(n + 1, Node{});
        res = 0;

        for (const auto &e : edges) {
            int u = e[0];
            int v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs(0, -1);

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
