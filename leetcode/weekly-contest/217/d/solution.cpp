#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define rall rbegin(a), rend(a)
#define lowbit(x) ((x) & (-(x)))
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

constexpr int N = 1e5 + 10;
int n, a[N];

class Solution {
public:
    int minimumDeviation(vector<int> &nums) {
        vector<int> vec;
        set<PII> se;
        for (auto &it : nums) {
            vec.push_back(it);
            int cnt = 0;
            while (it % 2 == 0) {
                it /= 2;
                ++cnt;
                vec.push_back(it);
            }
            if (!cnt) {
                vec.push_back(it * 2);
                cnt = 1;
            }
            se.insert(PII(it, cnt));
        }
        sort(all(vec));
        vec.erase(unique(all(vec)), vec.end());
        ll res = INT_MAX;
        for (auto &it : vec) {
            int ok = 1;
            while (1) {
                auto pos = *se.begin();
                se.erase(pos);
                if (pos.fi < it) {
                    if (pos.se == 0) {
                        ok = 0;
                        break;
                    }
                    --pos.se;
                    pos.fi *= 2;
                    se.insert(pos);
                } else {
                    se.insert(pos);
                    break;
                }
            }
            if (!ok)
                break;
            auto pos = se.end();
            --pos;
            chmin(res, (*pos).fi - it);
        }
        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
