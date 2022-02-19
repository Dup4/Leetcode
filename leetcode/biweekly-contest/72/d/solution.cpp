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

struct BIT {
    vector<ll> a;
    int n;
    void init(int n) {
        this->n = n + 10;
        a = vector<ll>(this->n, 0);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, ll v) {
        for (int i = x; i < n; i += lowbit(i)) a[i] += v;
    }
    ll query(int x) {
        ll ret = 0;
        for (int i = x; i > 0; i -= lowbit(i)) ret += a[i];
        return ret;
    }
    ll query(int l, int r) {
        if (l > r)
            return 0;
        return query(r) - query(l - 1);
    }
    void add(int l, int r, ll v) {
        if (l > r)
            return;
        add(l, v);
        add(r + 1, -v);
    }
} bf, bg;

class Solution {
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();

        vector<int> pos(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pos[nums2[i]] = i;
        }

        bf.init(n);
        bg.init(n);

        vector<ll> f(n + 1, 0), g(n + 1, 0);

        {
            for (int i = n - 1; i >= 0; i--) {
                int x = nums1[i], y = pos[x];
                f[x] = bf.query(y + 1);
                // dbg(i, f[x]);
                bf.add(1, y, 1);
            }
        }

        {
            for (int i = n - 1; i >= 0; i--) {
                int x = nums1[i], y = pos[x];
                g[x] = bg.query(y + 1);
                // dbg(i, g[x]);
                bg.add(1, y, f[x]);
            }
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += g[i];
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    {
        auto s = new Solution();
        auto a = vector<int>{2, 0, 1, 3};
        auto b = vector<int>{0, 1, 2, 3};
        auto ans = s->goodTriplets(a, b);
        dbg(ans);
    }

    return 0;
}

#endif
