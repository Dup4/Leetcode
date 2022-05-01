#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

struct node {
    int x, y, t;
};

int mv[][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
};

class Solution {
public:
    int maximumMinutes(vector<vector<int>> &grid) {
        int n = static_cast<int>(grid.size());
        int m = static_cast<int>(grid[0].size());

        auto ok = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) {
                return false;
            }

            return true;
        };

        auto check = [&](int x) -> bool {
            queue<node> f, p;
            auto g = vector<vector<int>>(grid);
            auto visf = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
            auto visp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (g[i][j] == 1) {
                        f.push({
                                .x = i,
                                .y = j,
                                .t = 0,
                        });

                        visf[i][j] = 1;
                    }
                }
            }

            auto inc = [&](int tt) {
                while (!f.empty()) {
                    auto ff = f.front();

                    int x = ff.x;
                    int y = ff.y;
                    int t = ff.t;

                    if (t >= tt) {
                        break;
                    }

                    f.pop();

                    g[x][y] = 1;

                    for (int i = 0; i < 4; i++) {
                        int nx = x + mv[i][0];
                        int ny = y + mv[i][1];
                        if (ok(nx, ny) && visf[nx][ny] == 0 && g[nx][ny] == 0) {
                            visf[nx][ny] = 1;
                            f.push({
                                    .x = nx,
                                    .y = ny,
                                    .t = t + 1,
                            });
                        }
                    }
                }
            };

            inc(x);

            if (g[0][0] != 0) {
                return false;
            }

            p.push({
                    .x = 0,
                    .y = 0,
                    .t = x,
            });

            visp[0][0] = 1;

            while (!p.empty()) {
                auto pp = p.front();
                p.pop();

                int x = pp.x;
                int y = pp.y;
                int t = pp.t;

                inc(t + 1);

                if (x == n - 1 && y == m - 1) {
                    return true;
                }

                if (g[x][y] == 1) {
                    continue;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = x + mv[i][0];
                    int ny = y + mv[i][1];
                    if (ok(nx, ny) && visp[nx][ny] == 0 && g[nx][ny] == 0) {
                        visp[nx][ny] = 1;
                        p.push({
                                .x = nx,
                                .y = ny,
                                .t = t + 1,
                        });
                    }
                }
            }

            return false;
        };

        int l = 0, r = 1e9, res = -1;
        while (r - l >= 0) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
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
