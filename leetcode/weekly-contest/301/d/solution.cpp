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

const int mod = 1e9 + 7;

namespace linear_seq {
typedef long long ll;
typedef vector<ll> VI;
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define pb push_back
#define SZ(x) ((int)(x).size())
ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
const ll mod = 1e9 + 7;
const int N = 1e5 + 10;
ll res[N], base[N], _c[N], _md[N];
vector<ll> Md;
void mul(ll *a, ll *b, ll k) {
    rep(i, 0, k + k) _c[i] = 0;
    rep(i, 0, k) if (a[i]) rep(j, 0, k) _c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
    for (ll i = k + k - 1; i >= k; i--)
        if (_c[i])
            rep(j, 0, SZ(Md)) _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % mod;
    rep(i, 0, k) a[i] = _c[i];
}
// a 系数 b 初值 b[n+1]=a[0]*b[n]+...
ll solve(ll n, VI a, VI b) {
    ll ans = 0, pnt = 0;
    ll k = SZ(a);
    assert(SZ(a) == SZ(b));
    rep(i, 0, k) _md[k - 1 - i] = -a[i];
    _md[k] = 1;
    Md.clear();
    rep(i, 0, k) if (_md[i] != 0) Md.push_back(i);
    rep(i, 0, k) res[i] = base[i] = 0;
    res[0] = 1;
    while ((1ll << pnt) <= n) pnt++;
    for (ll p = pnt; p >= 0; p--) {
        mul(res, res, k);
        if ((n >> p) & 1) {
            for (ll i = k - 1; i >= 0; i--) res[i + 1] = res[i];
            res[0] = 0;
            rep(j, 0, SZ(Md)) res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % mod;
        }
    }
    rep(i, 0, k) ans = (ans + res[i] * b[i]) % mod;
    if (ans < 0)
        ans += mod;
    return ans;
}
VI BM(VI s) {
    VI C(1, 1), B(1, 1);
    ll L = 0, m = 1, b = 1;
    rep(n, 0, SZ(s)) {
        ll d = 0;
        rep(i, 0, L + 1) d = (d + (ll)C[i] * s[n - i]) % mod;
        if (d == 0)
            ++m;
        else if (2 * L <= n) {
            VI T = C;
            ll c = mod - d * powmod(b, mod - 2) % mod;
            while (SZ(C) < SZ(B) + m) C.pb(0);
            rep(i, 0, SZ(B)) C[i + m] = (C[i + m] + c * B[i]) % mod;
            L = n + 1 - L;
            B = T;
            b = d;
            m = 1;
        } else {
            ll c = mod - d * powmod(b, mod - 2) % mod;
            while (SZ(C) < SZ(B) + m) C.pb(0);
            rep(i, 0, SZ(B)) C[i + m] = (C[i + m] + c * B[i]) % mod;
            ++m;
        }
    }
    return C;
}
ll gao(VI a, ll n) {
    VI c = BM(a);
    c.erase(c.begin());
    rep(i, 0, SZ(c)) c[i] = (mod - c[i]) % mod;
    return solve(n, c, VI(a.begin(), a.begin() + SZ(c)));
}
};  // namespace linear_seq

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int N = 100;
        auto f = vector<vector<int>>(N + 1, vector<int>(maxValue + 5, 0));

        for (int i = 1; i <= maxValue; i++) {
            f[1][i] = 1;
        }

        for (int i = 1; i < N; i++) {
            auto &cur = f[i];
            auto &nx = f[i + 1];

            for (int j = 1; j <= maxValue; j++) {
                for (int k = 1; j * k <= maxValue; k++) {
                    nx[j * k] += cur[j];
                    nx[j * k] %= mod;
                }
            }
        }

        auto g = vector<ll>();

        for (int i = 1; i <= N; i++) {
            g.push_back(0);
            for (int j = 1; j <= maxValue; j++) {
                g.back() += f[i][j];
                g.back() %= mod;
            }
        }

        if (n <= N) {
            return g[n - 1];
        }

        return int(linear_seq::gao(g, n - 1));
    }
};

#ifdef LOCAL

int main() {
    {
        auto s = Solution();
        auto res = s.idealArrays(10000, 10000);
        dbg(res);
    }

    return 0;
}

#endif
