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
int n, m, f[N], d[N];
vector<vector<int>> matrix;
vector<vector<int>> G;

int id(int x, int y) {
    return x * m + y;
}

struct UFS {
    int fa[N], rk[N];
    void init(int n) {
        memset(fa, -1, sizeof(fa[0]) * (n + 5));
        memset(rk, 0, sizeof(rk[0]) * (n + 5));
    }
    int find(int x) {
        return fa[x] == -1 ? x : fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            if (rk[fx] > rk[fy])
                swap(fx, fy);
            fa[fx] = fy;
            if (rk[fx] == rk[fy])
                ++rk[fy];
            return true;
        }
        return false;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
} ufs;

void topo() {
    queue<int> que;
    memset(f, 0, sizeof f);
    for (int i = 0; i < n * m; ++i) {
        if (d[i] == 0) {
            f[i] = 1;
            que.push(i);
        }
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto &v : G[u]) {
            chmax(f[v], f[u] + 1);
            if (--d[v] == 0) {
                que.push(v);
            }
        }
    }
}

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &_matrix) {
        matrix = _matrix;
        n = matrix.size();
        m = matrix[0].size();
        G.clear();
        G.resize(N);
        memset(d, 0, sizeof d);
        ufs.init(N - 10);
        for (int i = 0; i < n; ++i) {
            vector<pII> vec;
            for (int j = 0; j < m; ++j) {
                vec.push_back(pII(matrix[i][j], j));
            }
            sort(all(vec));
            for (int j = 1; j < m; ++j) {
                if (vec[j].fi == vec[j - 1].fi) {
                    int u = id(i, vec[j - 1].se);
                    int v = id(i, vec[j].se);
                    ufs.merge(u, v);
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            vector<pII> vec;
            for (int i = 0; i < n; ++i) {
                vec.push_back(pII(matrix[i][j], i));
            }
            sort(all(vec));
            for (int i = 1; i < n; ++i) {
                if (vec[i].fi == vec[i - 1].fi) {
                    int u = id(vec[i - 1].se, j);
                    int v = id(vec[i].se, j);
                    ufs.merge(u, v);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            vector<pII> vec;
            for (int j = 0; j < m; ++j) {
                vec.push_back(pII(matrix[i][j], j));
            }
            sort(all(vec));
            for (int j = 1; j < m; ++j) {
                if (vec[j].fi != vec[j - 1].fi) {
                    int u = ufs.find(id(i, vec[j - 1].se));
                    int v = ufs.find(id(i, vec[j].se));
                    G[u].push_back(v);
                    ++d[v];
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            vector<pII> vec;
            for (int i = 0; i < n; ++i) {
                vec.push_back(pII(matrix[i][j], i));
            }
            sort(all(vec));
            for (int i = 1; i < n; ++i) {
                if (vec[i].fi != vec[i - 1].fi) {
                    int u = ufs.find(id(vec[i - 1].se, j));
                    int v = ufs.find(id(vec[i].se, j));
                    G[u].push_back(v);
                    ++d[v];
                }
            }
        }
        topo();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) res[i][j] = f[ufs.find(id(i, j))];
        return res;
    }
};

void run() {}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int _T = nextInt();
    while (_T--) run();
    //    for (int kase = 1; kase <= _T; ++kase) {
    //        cout << "Case #" << kase << ": ";
    //        run();
    //    }
    //	while (cin >> n) run();
    //	run();
    return 0;
}
