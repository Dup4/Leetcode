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

const int N = 1e3 + 10;
int pri[N], check[N];
void sieve() {
    memset(check, 0, sizeof check);
    *pri = 0;
    for (int i = 2; i < N; ++i) {
        if (!check[i]) {
            pri[++*pri] = i;
        }
        for (int j = 1; j <= *pri; ++j) {
            if (1ll * i * pri[j] >= N)
                break;
            check[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}

class Solution {
public:
    int distinctPrimeFactors(vector<int> &nums) {
        sieve();

        set<int> se;

        sort(all(nums));
        nums.erase(unique(all(nums)), nums.end());

        for (const auto &a : nums) {
            if (check[a] == 0) {
                se.insert(a);
            } else {
                for (int i = 2; i <= a; i++) {
                    if (check[i] == 0 && a % i == 0) {
                        se.insert(i);
                    }
                }
            }
        }

        return int(se.size());
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
