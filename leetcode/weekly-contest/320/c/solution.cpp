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
    vector<vector<int>> G;
    int seats;
    pair<ll, int> dfs(int u, int fa) {
        ll cost = 0;
        int cnt = 1;

        for (const auto &v : G[u]) {
            if (v == fa) {
                continue;
            }

            auto p = dfs(v, u);
            cost += p.first;
            cost += (p.second + seats - 1) / seats;
            cnt += p.second;
        }

        return make_pair(cost, cnt);
    }

    long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
        int n = int(roads.size()) + 1;
        G = vector<vector<int>>(n + 1, vector<int>());
        this->seats = seats;

        for (const auto &r : roads) {
            int u = r[0];
            int v = r[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        return dfs(0, -1).first;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
