#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <stack>
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

int mv[][2] = {
        {0, 1},
        {1, 0},
};

struct node {
    int x, y, c;
};

class Solution {
public:
    vector<vector<char>> g;
    bool bfs() {
        int n = static_cast<int>(g.size());
        int m = static_cast<int>(g[0].size());

        const auto ok = [&](int x, int y) -> bool {
            if (x < 0 || x >= n || y < 0 || y >= m) {
                return false;
            }

            return true;
        };

        auto f = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(m + 1, vector<int>(210, 0)));

        if (g[0][0] == ')') {
            return false;
        }

        if (g[n - 1][m - 1] == '(') {
            return false;
        }

        queue<node> q;

        q.push({
                .x = 0,
                .y = 0,
                .c = 1,
        });

        f[0][0][1] = 1;

        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            int x = t.x;
            int y = t.y;
            int c = t.c;

            for (int i = 0; i < 2; i++) {
                int nx = x + mv[i][0];
                int ny = y + mv[i][1];
                int cc = c;

                if (ok(nx, ny)) {
                    if (g[nx][ny] == '(') {
                        ++cc;
                    } else {
                        --cc;
                    }

                    if (cc < 0) {
                        continue;
                    }

                    if (f[nx][ny][cc]) {
                        continue;
                    }

                    f[nx][ny][cc] = 1;
                    q.push({
                            .x = nx,
                            .y = ny,
                            .c = cc,
                    });
                }
            }
        }

        return f[n - 1][m - 1][0];
    }

    bool hasValidPath(vector<vector<char>> &grid) {
        g = vector<vector<char>>(grid);

        return bfs();
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
