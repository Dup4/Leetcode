#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define mkp make_pair
#define all(x) (x).begin(), (x).end()
using db = double;
using ll = long long;
using ull = unsigned long long;
using pII = pair<int, int>;
using pLL = pair<ll, ll>;
constexpr int mod = 1e9 + 7;
template <class T1, class T2>
inline void chadd(T1 &x, T2 y, int Mod = mod) {
    x += y;
    while (x >= Mod) x -= Mod;
    while (x < 0) x += Mod;
}
template <class T1, class T2>
inline void chmax(T1 &x, T2 y) {
    if (x < y)
        x = y;
}
template <class T1, class T2>
inline void chmin(T1 &x, T2 y) {
    if (x > y)
        x = y;
}
inline int nextInt() {
    int x;
    cin >> x;
    return x;
}
void rd() {}
template <class T, class... Ts>
void rd(T &arg, Ts &...args) {
    cin >> arg;
    rd(args...);
}
#define dbg(x...)                             \
    do {                                      \
        cout << "\033[32;1m" << #x << " -> "; \
        err(x);                               \
    } while (0)
void err() {
    cout << "\033[39;0m" << endl;
}
template <class T, class... Ts>
void err(const T &arg, const Ts &...args) {
    cout << arg << ' ';
    err(args...);
}
template <template <typename...> class T, typename t, typename... A>
void err(const T<t> &arg, const A &...args) {
    for (auto &v : arg) cout << v << ' ';
    err(args...);
}
void ptt() {
    cout << endl;
}
template <class T, class... Ts>
void ptt(const T &arg, const Ts &...args) {
    cout << ' ' << arg;
    ptt(args...);
}
template <class T, class... Ts>
void pt(const T &arg, const Ts &...args) {
    cout << arg;
    ptt(args...);
}
void pt() {}
template <template <typename...> class T, typename t, typename... A>
void pt(const T<t> &arg, const A &...args) {
    for (int i = 0, sze = arg.size(); i < sze; ++i) cout << arg[i] << " \n"[i == sze - 1];
    pt(args...);
}
inline ll qpow(ll base, ll n) {
    assert(n >= 0);
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return res;
}
// head
constexpr int N = 500 * 500 + 10;
int n, m;
vector<vector<int>> G;
int Move[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
int vis[N], fa[N], g[510][510];
int has;

void dfs(int u) {
    vis[u] = 1;
    for (auto &v : G[u])
        if (v != fa[u]) {
            fa[v] = u;
            if (vis[v]) {
                has = 1;
                return;
            }
            dfs(v);
            if (has)
                return;
        }
}

bool valid(int x, int y) {
    if (x < 0 || x > n || y < 0 || y > m)
        return false;
    return true;
}

bool ok(vector<pII> &vec) {
    int _n = SZ(vec);
    G.clear();
    G.resize(_n + 1);
    for (int i = 0; i < _n; ++i) {
        g[vec[i].fi][vec[i].se] = i + 1;
        vis[i + 1] = 0;
        fa[i + 1] = 0;
    }
    has = 0;
    //	pt("-----");
    for (int i = 0; i < _n; ++i) {
        int x = vec[i].fi, y = vec[i].se, u = i + 1;
        for (int j = 0; j < 4; ++j) {
            int nx = x + Move[j][0];
            int ny = y + Move[j][1];
            if (valid(nx, ny) && g[nx][ny]) {
                int v = g[nx][ny];
                G[u].push_back(v);
                //	pt(u, v);
            }
        }
    }
    //	pt("-----------");
    for (int i = 0; i < _n; ++i) {
        g[vec[i].fi][vec[i].se] = 0;
    }
    for (int i = 1; i <= _n; ++i) {
        if (!vis[i]) {
            dfs(i);
            //	if (has) pt(i);
            if (has)
                return true;
        }
    }
    return false;
}

class Solution {
public:
    bool containsCycle(vector<vector<char>> &grid) {
        n = SZ(grid);
        m = SZ(grid[0]);
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j) g[i][j] = 0;
        vector<pII> vec[30];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                vec[grid[i][j] - 'a'].push_back(pII(i, j));
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (SZ(vec[i]) && ok(vec[i]))
                return true;
        }
        return false;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
