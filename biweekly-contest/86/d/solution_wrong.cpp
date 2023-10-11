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

template <typename T>
class FenwickTree {
public:
    FenwickTree() = default;

    FenwickTree(const size_t n) {
        arr_.reserve(n);
    }

    void Init(int n) {
        n_ = n;
        high_bit_n_ = highBit(n_);
        arr_.assign(n_ + 1, 0);
    }

    void Add(int x, const T &v) {
        for (int i = x; i <= n_; i += lowBit(i)) {
            arr_[i] += v;
        }
    }

    // query prefix sum
    T Query(int x) const {
        T ret = 0;

        for (int i = x; i > 0; i -= lowBit(i)) {
            ret += arr_[i];
        }

        return ret;
    }

    T Query(int l, int r) const {
        if (l > r) {
            return 0;
        }

        return Query(r) - Query(l - 1);
    }

    T QueryKth(int k) {
        T p = 0;

        for (int lim = 1 << (high_bit_n_); lim; lim >>= 1) {
            if (p + lim <= n_ && arr_[p + lim] < k) {
                p += lim;
                k -= arr_[p];
            }
        }

        return p + 1;
    }

private:
    int lowBit(int x) const {
        return x & -x;
    }

    int highBit(int x) const {
        int res = 0;

        while (x) {
            ++res;
            x >>= 1;
        }

        return res;
    }

    int n_, high_bit_n_;
    std::vector<T> arr_;
};

static FenwickTree<int> f1(1e5 + 10);
static FenwickTree<ll> f2(1e5 + 10);

struct node {
    int c;
    int r;
    int ix;

    bool operator<(const node &other) const {
        if (c == other.c) {
            return r < other.r;
        }

        return c < other.c;
    }
};

class Solution {
public:
    int maximumRobots(vector<int> &c, vector<int> &r, long long b) {
        int n = int(c.size());

        auto v = vector<node>();
        for (int i = 0; i < n; i++) {
            v.emplace_back(node{
                    .c = c[i],
                    .r = r[i],
            });
        }

        sort(all(v), [](const node &a, const node &b) {
            return a.r < b.r;
        });

        for (int i = 0; i < n; i++) {
            v[i].ix = i + 1;
        }

        sort(all(v));

        f1.Init(n + 5);
        f2.Init(n + 5);

        int res = 0;

        for (int i = 0; i < n; i++) {
            int l = 1, r = n;
            while (r - l >= 0) {
                int mid = (l + r) >> 1;
                int cnt = f1.Query(1, mid);
                ll s = f2.Query(1, mid);
                ll tot = (s + v[i].r) * (cnt + 1) + v[i].c;
                if (tot <= b) {
                    l = mid + 1;
                    res = max(res, cnt + 1);
                } else {
                    r = mid - 1;
                }
            }

            f1.Add(v[i].ix, 1);
            f2.Add(v[i].ix, v[i].r);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
