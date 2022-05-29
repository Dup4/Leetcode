#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>
#include <utility>
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

const int INF = 0x3f3f3f3f;

struct node {
    int x, y, w;
    node(int x, int y, int w) : x(x), y(y), w(w) {}

    bool operator<(const node &rhs) const {
        return w > rhs.w;
    }
};

int mv[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    int minimumObstacles(vector<vector<int>> &g) {
        int n = g.size();
        int m = g[0].size();

        priority_queue<node> pq;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));

        dp[0][0] = g[0][0];

        pq.push(node(0, 0, g[0][0]));

        while (!pq.empty()) {
            node cur = pq.top();
            pq.pop();

            if (cur.x == n - 1 && cur.y == m - 1) {
                return cur.w;
            }

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + mv[i][0];
                int ny = cur.y + mv[i][1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }

                int nw = cur.w + g[nx][ny];

                if (dp[nx][ny] <= nw) {
                    continue;
                }

                dp[nx][ny] = nw;

                pq.push(node(nx, ny, nw));
            }
        }

        assert(false);
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
