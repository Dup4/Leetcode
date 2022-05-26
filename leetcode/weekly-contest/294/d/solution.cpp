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

struct node {
    int x, l, r;

    ll GetSum(const vector<ll> &suffix_sum) {
        ll ans = 0;

        ans += 1ll * x * (suffix_sum[l] - suffix_sum[r + 1] + mod) % mod;
        ans %= mod;

        return ans;
    }

    ll GetBaseSum() {
        return 1ll * x * (r - l + 1);
    }
};

class Solution {
public:
    int totalStrength(vector<int> &a) {
        int n = (int)a.size();
        vector<vector<ll>> suffix_sum(2, vector<ll>(n + 5, 0));

        for (int i = n; i >= 1; i--) {
            suffix_sum[0][i] = (suffix_sum[0][i + 1] + a[i - 1]) % mod;
        }

        for (int i = n; i >= 1; i--) {
            suffix_sum[1][i] = (suffix_sum[1][i + 1] + suffix_sum[0][i]) % mod;
        }

        vector<node> v;

        ll sum = 0;
        ll base_sum = 0;
        ll res = 0;

        for (int i = 0; i < n; i++) {
            auto t = node();
            t.x = a[i];
            t.l = i + 1;
            t.r = i + 1;

            while (!v.empty()) {
                if (v.back().x < t.x) {
                    break;
                }

                sum = (sum - v.back().GetSum(suffix_sum[1]) + mod) % mod;
                base_sum = (base_sum - v.back().GetBaseSum() + mod) % mod;
                t.l = v.back().l;
                v.pop_back();
            }

            v.push_back(t);
            sum = (sum + t.GetSum(suffix_sum[1])) % mod;
            base_sum = (base_sum + t.GetBaseSum()) % mod;
            res = (res + sum) % mod;
            res -= 1ll * base_sum * suffix_sum[0][i + 2] % mod;
            res += mod;
            res %= mod;
        }

        return int(res);
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
