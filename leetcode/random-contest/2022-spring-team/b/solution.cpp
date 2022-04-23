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
inline bool chmax(T& a, const S& b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T& a, const S& b) {
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
    int x;
    int y;
    int cost;
    bool operator<(const node& other) const {
        return cost > other.cost;
    }
};

int mv[][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
};

char sign[] = {
        '>',
        '<',
        'v',
        '^',
};

class Solution {
public:
    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
        int n = matrix.size();
        int m = matrix[0].size();

        auto ok = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) {
                return false;
            }

            return true;
        };

        auto bfs = [&](int sx, int sy, int ex, int ey) {
            auto dis = vector<vector<int>>(n + 1, vector<int>(m + 1, INF));

            dis[sx][sy] = 0;

            priority_queue<node> pq;
            pq.push({
                    .x = sx,
                    .y = sy,
                    .cost = 0,
            });

            while (!pq.empty()) {
                auto top = pq.top();
                pq.pop();

                int x = top.x;
                int y = top.y;

                if (x == ex && y == ey) {
                    break;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = x + mv[i][0];
                    int ny = y + mv[i][1];
                    int cos = dis[x][y] + (matrix[x][y] != sign[i]);

                    if (ok(nx, ny) && dis[nx][ny] > cos) {
                        pq.push({
                                .x = nx,
                                .y = ny,
                                .cost = cos,
                        });

                        dis[nx][ny] = cos;
                    }
                }
            }

            return dis[ex][ey];
        };

        return bfs(start[0], start[1], end[0], end[1]);
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
