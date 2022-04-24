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
inline bool chmax(T& a, const S& b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T& a, const S& b) {
    return a > b ? a = b, 1 : 0;
}

#ifdef LOCAL
#include <debug.hpp>
#else
#define dbg(...)
#endif
// head

const int N = 2e5 + 10;

struct BIT {
    int a[N];
    int n;
    void init(int n) {
        this->n = n;
        memset(a, 0, sizeof(a[0]) * (n + 5));
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
} bit;

struct Hash {
    vector<db> a;
    db& operator[](int x) {
        return a[x - 1];
    }
    int size() {
        return a.size();
    }
    void init() {
        a.clear();
    }
    void add(db x) {
        a.push_back(x);
    }
    void gao() {
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }
    int get(db x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }
} hs;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        hs.init();

        for (const auto& f : flowers) {
            hs.add(f[0]);
            hs.add(f[1]);
        }

        for (const auto& p : persons) {
            hs.add(p);
        }

        hs.gao();

        bit.init(hs.size() + 5);

        for (const auto& f : flowers) {
            int l = hs.get(f[0]);
            int r = hs.get(f[1]);
            bit.add(l, r, 1);
        }

        auto res = vector<int>();
        for (const auto& p : persons) {
            res.push_back(bit.query(hs.get(p)));
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
