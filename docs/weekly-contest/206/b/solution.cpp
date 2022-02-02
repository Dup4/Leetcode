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
inline void chadd(T1& x, T2 y, int Mod = mod) {
    x += y;
    while (x >= Mod) x -= Mod;
    while (x < 0) x += Mod;
}
template <class T1, class T2>
inline void chmax(T1& x, T2 y) {
    if (x < y)
        x = y;
}
template <class T1, class T2>
inline void chmin(T1& x, T2 y) {
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
void rd(T& arg, Ts&... args) {
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
void err(const T& arg, const Ts&... args) {
    cout << arg << ' ';
    err(args...);
}
template <template <typename...> class T, typename t, typename... A>
void err(const T<t>& arg, const A&... args) {
    for (auto& v : arg) cout << v << ' ';
    err(args...);
}
void ptt() {
    cout << endl;
}
template <class T, class... Ts>
void ptt(const T& arg, const Ts&... args) {
    cout << ' ' << arg;
    ptt(args...);
}
template <class T, class... Ts>
void pt(const T& arg, const Ts&... args) {
    cout << arg;
    ptt(args...);
}
void pt() {}
template <template <typename...> class T, typename t, typename... A>
void pt(const T<t>& arg, const A&... args) {
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
constexpr int N = 5e2 + 10;
int n;
int vis[N], g[N][N];

inline void ok(int x, int y, int u, int v) {
    if (g[x][u] < g[x][y] && g[u][x] < g[u][v])
        vis[x] = 1;
}

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int res = 0;
        for (int i = 0; i <= n; ++i) vis[i] = 0;
        int m = n / 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                g[i][preferences[i][j]] = j;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j)
                if (i != j) {
                    int x = pairs[i][0], y = pairs[i][1];
                    int u = pairs[j][0], v = pairs[j][1];
                    ok(x, y, u, v);
                    ok(x, y, v, u);
                    ok(y, x, u, v);
                    ok(y, x, v, u);
                }
        }
        for (int i = 0; i < n; ++i) res += vis[i];
        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
