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

const int N = 1e3 + 10;
PII h[N];

class Solution {
public:
    void init() {
        for (int i = 2; i <= 1000; i++) {
            int x = i;

            while (x) {
                if (x % 2 == 0) {
                    x /= 2;
                    ++h[i].first;
                } else if (x % 5 == 0) {
                    x /= 5;
                    ++h[i].second;
                } else {
                    break;
                }
            }
        }
    }

    int maxTrailingZeros(vector<vector<int>> &grid) {
        if (h[2] != PII(1, 0)) {
            init();
        }

        int n = grid.size();
        int m = grid[0].size();

        auto f = vector<vector<PII>>(n + 1, vector<PII>(m + 1, PII(0, 0)));
        auto g = vector<vector<PII>>(n + 1, vector<PII>(m + 1, PII(0, 0)));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = grid[i][j];
                if (!j) {
                    f[i][j] = h[x];
                } else {
                    f[i][j] = PII(f[i][j - 1].first + h[x].first, f[i][j - 1].second + h[x].second);
                }
            }

            for (int j = m - 1; j >= 0; j--) {
                int x = grid[i][j];
                if (j == m - 1) {
                    g[i][j] = h[x];
                } else {
                    g[i][j] = PII(g[i][j + 1].first + h[x].first, g[i][j + 1].second + h[x].second);
                }
            }
        }

        int res = 0;
        for (int j = 0; j < m; j++) {
            {
                PII now(0, 0);
                for (int i = 0; i < n; i++) {
                    {
                        PII cur = now;
                        cur.first += f[i][j].first;
                        cur.second += f[i][j].second;

                        int y = min(cur.first, cur.second);
                        if (y > res) {
                            res = y;
                        }
                    }

                    {
                        PII cur = now;
                        cur.first += g[i][j].first;
                        cur.second += g[i][j].second;

                        int y = min(cur.first, cur.second);
                        if (y > res) {
                            res = y;
                        }
                    }

                    int x = grid[i][j];
                    now.first += h[x].first;
                    now.second += h[x].second;
                }
            }

            {
                PII now(0, 0);
                for (int i = n - 1; i >= 0; i--) {
                    {
                        PII cur = now;
                        cur.first += f[i][j].first;
                        cur.second += f[i][j].second;

                        int y = min(cur.first, cur.second);
                        if (y > res) {
                            res = y;
                        }
                    }

                    {
                        PII cur = now;
                        cur.first += g[i][j].first;
                        cur.second += g[i][j].second;

                        int y = min(cur.first, cur.second);
                        if (y > res) {
                            res = y;
                        }
                    }

                    int x = grid[i][j];
                    now.first += h[x].first;
                    now.second += h[x].second;
                }
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
