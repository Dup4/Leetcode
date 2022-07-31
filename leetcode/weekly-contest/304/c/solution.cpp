#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>
#include <vector>

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

constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int closestMeetingNode(vector<int> &e, int node1, int node2) {
        int n = int(e.size());
        auto bfs = [&n, &e](int st) {
            auto dis = vector<int>(n, INF);
            dis[st] = 0;

            queue<int> q;
            q.push(st);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                int nx = e[u];
                if (nx == -1) {
                    continue;
                }

                if (dis[nx] <= dis[u] + 1) {
                    continue;
                }

                q.push(nx);
                dis[nx] = dis[u] + 1;
            }

            return dis;
        };

        auto dis1 = bfs(node1);
        auto dis2 = bfs(node2);

        int dis = INF;
        int res = -1;

        for (int i = 0; i < n; ++i) {
            if (dis1[i] == INF || dis2[i] == INF) {
                continue;
            }

            if (chmin(dis, max(dis1[i], dis2[i]))) {
                res = i;
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
