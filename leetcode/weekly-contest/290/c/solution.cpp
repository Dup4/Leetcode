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

struct R {
    int l, h, ix;
    bool operator<(const R& other) const {
        if (l == other.l) {
            return h < other.h;
        }

        return l < other.l;
    }
};

const int N = 1e5 + 10;

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
} hl, hh;

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int np = points.size();

        hl.init();
        hh.init();

        for (const auto& r : rectangles) {
            hl.add(r[0]);
            hh.add(r[1]);
        }

        for (const auto& p : points) {
            hl.add(p[0]);
            hh.add(p[1]);
        }

        hl.gao();
        hh.gao();

        auto vr = vector<vector<R>>(hl.size() + 1, vector<R>());
        for (const auto& r : rectangles) {
            int l = hl.get(r[0]);
            int h = hh.get(r[1]);

            vr[l].push_back({
                    .l = l,
                    .h = h,
                    .ix = 0,
            });
        }

        int ix = 0;
        auto vp = vector<vector<R>>(hl.size() + 1, vector<R>());
        for (const auto& p : points) {
            int l = hl.get(p[0]);
            int h = hh.get(p[1]);

            vp[l].push_back({
                    .l = l,
                    .h = h,
                    .ix = ix,
            });

            ix++;
        }

        auto res = vector<int>(np, 0);

        bit.init(hh.size() + 5);

        for (int i = hl.size(); i >= 1; i--) {
            for (const auto& r : vr[i]) {
                bit.add(r.h, 1);
            }

            for (const auto& p : vp[i]) {
                res[p.ix] = bit.query(p.h, hh.size());
            }
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
