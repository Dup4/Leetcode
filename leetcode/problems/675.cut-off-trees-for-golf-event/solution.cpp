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

class Solution {
public:
    int n, m;
    struct node {
        int x, y, v;
        bool operator<(const node& other) const {
            return v < other.v;
        }
    };

    const inline static int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool ok(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return false;
        }

        return true;
    }

    int bfs(int sx, int sy, int ex, int ey, vector<vector<int>>& f) {
        auto vis = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        queue<node> q;
        q.push({.x = sx, .y = sy, .v = 0});
        vis[sx][sy] = 1;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            if (front.x == ex && front.y == ey) {
                f[ex][ey] = 1;
                return front.v;
            }

            for (int i = 0; i < 4; i++) {
                int nx = front.x + dir[i][0];
                int ny = front.y + dir[i][1];
                if (ok(nx, ny) && !vis[nx][ny] && f[nx][ny] >= 1) {
                    vis[nx][ny] = 1;
                    q.push({.x = nx, .y = ny, .v = front.v + 1});
                }
            }
        }

        return -1;
    }

    int cutOffTree(vector<vector<int>>& f) {
        n = f.size();
        m = f[0].size();

        auto tree = vector<node>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (f[i][j] > 1) {
                    tree.push_back({.x = i, .y = j, .v = f[i][j]});
                }
            }
        }

        sort(tree.begin(), tree.end());

        int sx = 0, sy = 0;
        int res = 0;
        for (const auto& o : tree) {
            int cur = bfs(sx, sy, o.x, o.y, f);
            if (cur == -1) {
                return cur;
            }

            res += cur;
            sx = o.x;
            sy = o.y;
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
