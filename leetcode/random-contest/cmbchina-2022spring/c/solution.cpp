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

const int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<int> lightSticks(int h, int w, vector<int> &ix) {
        int tot_n = (w + 1) * (h + 1);
        int tot_m = w * (2 * h + 1) + h;
        auto vis = vector<int>(tot_m, 1);
        for (auto &i : ix) {
            vis[i] = 0;
        }

        auto g = vector<vector<int>>(tot_n, vector<int>());
        int base = 0;
        for (int i = 0, o = 0; i < 2 * h + 1; i++) {
            base = (i / 2) * (w + 1);
            if (i % 2 == 0) {
                for (int j = 1; j < w + 1; j++) {
                    if (!vis[o++]) {
                        continue;
                    }

                    int u = base + j;
                    int v = base + j - 1;
                    g[u].push_back(v);
                    g[v].push_back(u);
                }
            } else {
                for (int j = 0; j < w + 1; j++) {
                    if (!vis[o++]) {
                        continue;
                    }

                    int u = base + j;
                    int v = base + w + 1 + j;
                    g[u].push_back(v);
                    g[v].push_back(u);
                }
            }
        }

        auto no_need = vector<int>(tot_n, 0);
        for (int i = 0; i < tot_n; i++) {
            if (g[i].empty()) {
                no_need[i] = 1;
            }
        }

        auto bfs = [&](int s) {
            auto dis = vector<int>(tot_n, INF);
            for (int i = 0; i < tot_n; i++) {
                if (no_need[i]) {
                    dis[i] = 0;
                }
            }

            queue<int> q;
            q.push(s);
            dis[s] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto &v : g[u]) {
                    if (dis[v] > dis[u] + 1) {
                        q.push(v);
                        dis[v] = dis[u] + 1;
                    }
                }
            }

            return *max_element(all(dis));
        };

        int res = INF;
        auto res_list = vector<int>();
        for (int i = 0; i < tot_n; i++) {
            if (no_need[i]) {
                continue;
            }

            int now = bfs(i);
            if (now < res) {
                res = now;
                res_list.clear();
                res_list.push_back(i);
            } else if (now == res) {
                res_list.push_back(i);
            }
        }

        if (res == INF) {
            return vector<int>();
        }

        return res_list;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
