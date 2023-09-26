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

    void dfs(int x, int y, vector<vector<char>> &board) {
        board[x][y] = 'B';

        for (const auto &d : dir) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (!is_valid_point(nx, ny)) {
                continue;
            }

            if (board[nx][ny] == 'X' || board[nx][ny] == 'B') {
                continue;
            }

            dfs(nx, ny, board);
        }
    }

    void solve(vector<vector<char>> &board) {
        n = int(board.size());
        m = int(board[0].size());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (board[i][j] == 'O') {
                        dfs(i, j, board);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }

                if (board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    int n, m;

    inline const static auto dir = vector<vector<int>>({
            {0, 1},
            {1, 0},
            {-1, 0},
            {0, -1},
    });
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
