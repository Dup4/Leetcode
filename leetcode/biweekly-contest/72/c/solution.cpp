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

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum & 1) {
            return {};
        }

        vector<long long> res;
        for (long long i = 2;; i += 2) {
            if (finalSum >= i) {
                finalSum -= i;
                res.push_back(i);
            }

            if (finalSum == 0) {
                break;
            }

            if (res.back() >= finalSum) {
                break;
            }
        }

        if (!res.empty() && res.back() >= finalSum) {
            res.back() += finalSum;
            finalSum = 0;
        }

        if (finalSum) {
            res.push_back(finalSum);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
