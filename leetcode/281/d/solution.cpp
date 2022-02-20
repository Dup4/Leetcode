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

const int N = 1e5 + 10;
const int M = 1e5;
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

vector<PII> getfac(ll x) {
    vector<PII> fac;
    for (int i = 2; 1ll * i * i <= x; ++i) {
        if (x % i == 0) {
            PII it = PII(i, 0);
            while (x % i == 0) {
                ++it.se;
                x /= i;
            }
            fac.push_back(it);
        }
    }
    if (x != 1)
        fac.push_back(PII(x, 1));
    return fac;
}

class Solution {
public:
    long long coutPairs(vector<int> &nums, int k) {
        // sieve();

        vector<int> cnt(N, 0);
        for (auto &v : nums) {
            ++cnt[v];
        }

        vector<long long> f(N, 0);
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j * i <= M; j++) {
                f[i] += cnt[j * i];
            }
        }

        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int gcd = __gcd(x, k);
            int y = k / gcd;
            res += f[y];

            if (1ll * x * x % k == 0) {
                --res;
            }
        }

        return res / 2;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
