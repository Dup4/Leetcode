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

// 0 1 1 0
// 1 0 0 1
// 0 1 1 0

// X X X X
// X O O X
// X X O X
// X O X X

struct Node {
    int l{-1}, r{-1}, u{-1}, d{-1};
};

class Solution {
public:
    bool is_valid_point(int x, int y) {
        if (x < 0 || x >= n) {
            return false;
        }

        if (y < 0 || y >= m) {
            return false;
        }

        return true;
    }

    void dfs(int x, int y, int cur_color) {
        color_[x][y] = cur_color;

        for (const auto &d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!is_valid_point(nx, ny)) {
                continue;
            }

            if (board_[nx][ny] != 'X') {
                continue;
            }

            if (color_[nx][ny]) {
                continue;
            }

            dfs(nx, ny, cur_color);
        }
    }

    void solve(vector<vector<char>> &board) {
        n = int(board.size());
        m = int(board[0].size());
        board_ = board;

        color_ = vector<vector<int>>(n + 5, vector<int>(m + 5, 0));
        int max_color = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X' && color_[i][j] == 0) {
                    dfs(i, j, max_color);
                    ++max_color;
                }
            }
        }

        auto mp = vector<vector<Node>>(n + 5, vector<Node>(m + 5, Node{}));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') {
                    auto node = Node();
                    node.l = j;
                    node.r = j;
                    node.u = i;
                    node.d = i;

                    mp[i][j] = node;
                } else {
                    auto node = Node();

                    if (i) {
                        node.u = mp[i - 1][j].u;
                    }

                    if (j) {
                        node.l = mp[i][j - 1].l;
                    }

                    mp[i][j] = node;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (board[i][j] != 'X') {
                    auto &node = mp[i][j];

                    if (i < n - 1) {
                        node.d = mp[i + 1][j].d;
                    }

                    if (j < m - 1) {
                        node.r = mp[i][j + 1].r;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                const auto &node = mp[i][j];
                if (node.l == -1 || node.r == -1 || node.u == -1 || node.d == -1) {
                    continue;
                }

                auto cur_color = color_[i][node.l];
                if (color_[i][node.r] != cur_color) {
                    continue;
                }

                if (color_[node.u][j] != cur_color) {
                    continue;
                }

                if (color_[node.d][j] != cur_color) {
                    continue;
                }

                board[i][j] = 'X';
            }
        }
    }

private:
    int n, m;
    vector<vector<int>> color_;
    vector<vector<char>> board_;

    inline const static auto dir = vector<vector<int>>({
            {0, 1},
            {1, 0},
            {-1, 0},
            {0, -1},
            {1, 1},
            {1, -1},
            {-1, 1},
            {-1, -1},
    });
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
