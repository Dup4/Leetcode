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

const int N = 1e5 + 10;

struct Hash {
    ll base[N];
    ll a[N];
    ll p, mod;

    void init(ll p, ll mod, int n) {
        this->p = p;
        this->mod = mod;

        base[0] = 1;
        for (int i = 1; i <= n; ++i) {
            base[i] = base[i - 1] * p % mod;
        }
    }

    void gao(string &s) {
        int n = s.length();
        a[0] = 0;
        a[1] = s[0] - 'a' + 1;
        for (int i = 1; i <= n; ++i) {
            a[i] = ((a[i - 1] * p) % mod + (s[i - 1] - 'a' + 1)) % mod;
        }
    }

    ll get(int l, int r) {
        return (a[r] - a[l - 1] * base[r - l + 1] % mod + mod) % mod;
    }
} hs;

class Solution {
public:
    string subStrHash(string s, int p, int mod, int k, int hashValue) {
        int n = s.length();

        string t = s;
        reverse(all(t));

        hs.init(p, mod, n);
        hs.gao(t);

        string ans = "";

        for (int i = 0; i + k <= n; i++) {
            if (hs.get(i + 1, i + k) == hashValue) {
                ans = s.substr(n - i - k, k);
            }
        }

        return ans;
    }
};

#ifdef LOCAL

int main() {
    auto s = Solution();

    {
        auto ans = s.subStrHash("leetcode", 7, 20, 2, 0);
        dbg(ans);
    }

    {
        auto ans = s.subStrHash("fbxzaad", 31, 100, 3, 32);
        dbg(ans);
    }
    return 0;
}

#endif
