#include <bits/stdc++.h>
#include <cstdarg>
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
#define dbg(x...)             \
    do {                      \
        cout << #x << " -> "; \
        err(x);               \
    } while (0)

void err() {
    cout << endl;
}

template <class T, class... Ts>
void err(const T &arg, const Ts &...args) {
    cout << arg << ' ';
    err(args...);
}

#else
#define dbg(...)
#endif
// head

const int INF = 0x3f3f3f3f;

struct node {
    int x, y, t;

    bool operator<(const node &other) const {
        return t < other.t;
    }
};

struct Hash {
    vector<int> a;

    int &operator[](int x) {
        return a[x - 1];
    }

    int size() {
        return a.size();
    }

    void init() {
        a.clear();
    }

    void add(int x) {
        a.push_back(x);
    }

    void gao() {
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }

    int get(int x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }
} hs;

auto dis(int sx, int sy, int ex, int ey) -> int {
    return abs(sx - ex) + abs(sy - ey);
}

class Solution {
public:
    int getMaximumNumber(vector<vector<int>> &moles) {
        int n = moles.size();

        hs.init();
        hs.add(0);
        hs.add(1);
        hs.add(2);

        for (const auto &m : moles) {
            hs.add(m[0]);
        }

        hs.gao();
        int size = hs.size();

        int hasInit = 0;

        vector<node> v[size + 10];
        for (const auto &m : moles) {
            v[hs.get(m[0])].push_back({
                    .x = m[1],
                    .y = m[2],
                    .t = m[0],
            });

            if (m[0] == 0 && m[1] == 1 && m[2] == 1) {
                hasInit = 1;
            }
        }

        auto f = vector<vector<vector<int>>>(n + 5, vector<vector<int>>(3, vector<int>(3, -INF)));

        int res = 0;
        f[hs.get(0)][1][1] = hasInit;
        res = hasInit;

        for (int i = 1; i <= size; ++i) {
            for (auto it : v[i]) {
                for (int pre = i - 1; pre >= max(1, i - 4); --pre) {
                    for (int x = 0; x <= 2; ++x) {
                        for (int y = 0; y <= 2; ++y) {
                            int d = dis(x, y, it.x, it.y);
                            if (d > hs[i] - hs[pre]) {
                                continue;
                            }

                            f[i][it.x][it.y] = max(f[pre][x][y] + 1, f[i][it.x][it.y]);
                            res = max(res, f[i][it.x][it.y]);
                        }
                    }
                }
            }

            for (int x = 0; x <= 2; ++x) {
                for (int y = 0; y <= 2; ++y) {
                    if (dis(1, 1, x, y) <= hs[i]) {
                        f[i][x][y] = max(f[i][x][y], 0);
                    }
                }
            }
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    {
        auto s = new Solution();
        auto m = vector<vector<int>>({
                {1, 1, 0},
                {2, 0, 1},
                {4, 2, 2},
        });

        auto ans = s->getMaximumNumber(m);
        dbg(ans);

        m = vector<vector<int>>({{2, 0, 2}, {5, 2, 0}, {4, 1, 0}, {1, 2, 1}, {3, 0, 2}});
        ans = s->getMaximumNumber(m);
        dbg(ans);

        m = vector<vector<int>>({{0, 1, 0}, {0, 0, 1}});
        ans = s->getMaximumNumber(m);
        dbg(ans);

        m = vector<vector<int>>({{0, 1, 1}});
        ans = s->getMaximumNumber(m);
        dbg(ans);
    }
    return 0;
}

#endif
