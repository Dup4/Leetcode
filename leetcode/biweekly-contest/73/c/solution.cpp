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

class Solution {
public:
    vector<int> bfs(int st, int n, const vector<vector<int>> &G) {
        vector<int> cnt(n + 1, 0), res;

        queue<int> q;
        q.push(st);
        cnt[st] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto &to : G[u]) {
                if (cnt[to]) {
                    continue;
                }

                cnt[to] = 1;
                q.push(to);
                res.push_back(to);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<vector<int>> G(n + 5, vector<int>{});

        for (const auto &e : edges) {
            int u = e[0];
            int v = e[1];
            G[v].push_back(u);
        }

        vector<vector<int>> res(n, vector<int>{});
        for (int i = 0; i < n; i++) {
            res[i] = bfs(i, n, G);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
