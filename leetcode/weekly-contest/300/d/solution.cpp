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

constexpr int mod = 1e9 + 7;

struct node {
    int x, y, v;
    node(int x, int y, int v) : x(x), y(y), v(v) {}
    bool operator<(const node &other) const {
        return v < other.v;
    }
};

int dir[][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
};

class Solution {
public:
    int countPaths(vector<vector<int>> &grid) {
        int m = int(grid.size());
        int n = int(grid[0].size());

        auto vec = vector<node>();
        vec.reserve(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vec.emplace_back(i, j, grid[i][j]);
            }
        }

        sort(all(vec));

        auto f = vector<vector<int>>(m + 1, vector<int>(n + 1, 1));
        int res = 0;

        for (auto &a : vec) {
            for (int i = 0; i < 4; i++) {
                int nx = a.x + dir[i][0];
                int ny = a.y + dir[i][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }

                if (a.v >= grid[nx][ny]) {
                    continue;
                }

                f[nx][ny] += f[a.x][a.y];
                f[nx][ny] %= mod;
            }

            res += f[a.x][a.y];
            res %= mod;
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
