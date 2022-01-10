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
constexpr int N = 1e2 + 10;
int n, m;
vector<vector<int>> heights;
int vis[N][N];

int Move[][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

bool valid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}

bool ok(int xx) {
    memset(vis, 0, sizeof vis);
    queue<pII> que;
    que.push(pII(0, 0));
    while (!que.empty()) {
        pII front = que.front();
        que.pop();
        int x = front.fi;
        int y = front.se;
        if (x == n - 1 && y == m - 1)
            return true;
        for (int i = 0; i < 4; ++i) {
            int _x = x + Move[i][0];
            int _y = y + Move[i][1];
            if (valid(_x, _y) && vis[_x][_y] == 0 && abs(heights[_x][_y] - heights[x][y]) <= xx) {
                que.push(pII(_x, _y));
                vis[_x][_y] = 1;
            }
        }
    }
    return false;
}

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &_heights) {
        heights = _heights;
        n = heights.size();
        m = heights[0].size();
        int l = 0, r = 1e6, res = 1e6;
        while (r - l >= 0) {
            int mid = (l + r) >> 1;
            if (ok(mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
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
