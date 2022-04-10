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

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int goShopping(vector<int> &A, vector<int> &B) {
        int n = A.size();

        auto sol = [&](int flag) {
            auto f = vector<vector<vector<PII>>>(n + 1, vector<vector<PII>>(4, vector<PII>(4, PII(INF, INF))));

            auto C = vector<PII>();
            for (int i = 0; i < n; i++) {
                C.push_back(PII(B[i], A[i]));
            }

            f[0][0][0] = PII(0, 0);

            auto Min = [&flag](const PII &a, const PII &b) {
                if (flag) {
                    if ((1ll * a.se * 7 + 1ll * a.fi * 10) <= (1ll * b.se * 7 + 1ll * b.fi * 10)) {
                        return a;
                    }

                    return b;
                }

                if (a.fi + a.se <= b.fi + b.se) {
                    return a;
                }

                return b;
            };

            sort(all(C));
            reverse(all(C));

            for (int i = 1; i <= n; i++) {
                PII now = C[i - 1];
                for (int j = 0; j <= 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        if (j) {
                            PII cur = f[i - 1][j - 1][k];
                            cur.se += now.se;
                            f[i][j][k] = Min(f[i][j][k], cur);
                        }

                        if (j == 3) {
                            PII cur = f[i - 1][j][k];
                            cur.se += now.se;
                            f[i][j][k] = Min(f[i][j][k], cur);
                        }

                        if (k == 0) {
                            PII cur = f[i - 1][j][2];
                            f[i][j][k] = Min(f[i][j][k], cur);
                        } else {
                            PII cur = f[i - 1][j][k - 1];
                            cur.fi += now.fi;
                            f[i][j][k] = Min(f[i][j][k], cur);
                        }
                    }
                }
            }

            ll res = INF;
            for (int j = 0; j <= 3; j++) {
                for (int k = 0; k < 3; k++) {
                    PII cur = f[n][j][k];
                    ll cur_res = cur.fi;

                    if (j == 3) {
                        cur_res += 1ll * cur.se * 7 / 10;
                    } else {
                        cur_res += cur.se;
                    }

                    res = min(res, cur_res);
                }
            }

            return res;
        };

        return min(sol(0), sol(1));
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
