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

const int MOD = 1e9 + 7;

class Solution {
public:
    int offset(int x) {
        return x + 1050;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        int gap = abs(startPos - endPos);
        if ((gap & 1) != (k & 1)) {
            return 0;
        }

        auto f = vector<vector<int>>(3100, vector<int>(k + 5, 0));
        auto visit = vector<vector<int>>(3100, vector<int>(k + 5, 0));

        auto q = queue<pair<int, int>>();

        auto st = make_pair(offset(startPos), 0);
        f[st.first][st.second] = 1;
        q.push(st);

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            if (p.second == k) {
                continue;
            }

            {
                auto _p = p;
                _p.first++;
                _p.second++;
                f[_p.fi][_p.se] += f[p.fi][p.se];
                f[_p.fi][_p.se] %= MOD;
                if (!visit[_p.fi][_p.se]) {
                    q.push(_p);
                    visit[_p.fi][_p.se] = true;
                }
            }

            {
                auto _p = p;
                _p.first--;
                _p.second++;
                f[_p.fi][_p.se] += f[p.fi][p.se];
                f[_p.fi][_p.se] %= MOD;
                if (!visit[_p.fi][_p.se]) {
                    q.push(_p);
                    visit[_p.fi][_p.se] = true;
                }
            }
        }

        auto ed = make_pair(offset(endPos), k);
        return f[ed.fi][ed.se];
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
