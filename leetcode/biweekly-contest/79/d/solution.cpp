#include <bits/stdc++.h>
#include <algorithm>
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
        for (int i = x; i <= n_; i += lowbit(i)) {
            arr_[i] += v;
        }
    }

    // query prefix sum
    T Query(int x) const {
        T ret = 0;

        for (int i = x; i > 0; i -= lowbit(i)) {
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
    int lowbit(int x) const {
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

const int N = 1e5 + 10;

struct SEG {
    struct node {
        int cur, m;
        node() {
            cur = m = 0;
        }

        node operator+(const node &other) const {
            node res = node();
            res.m = max(m, other.m);
            return res;
        }
    } t[N << 2];
    int res;

    void build(int id, int l, int r, int x) {
        t[id] = node();

        if (l == r) {
            t[id].cur = x;
            t[id].m = x;
            return;
        }

        int mid = (l + r) >> 1;
        build(id << 1, l, mid, x);
        build(id << 1 | 1, mid + 1, r, x);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }

    void update(int id, int l, int r, int x, int v) {
        if (l == r) {
            t[id].cur += v;
            t[id].m += v;
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
            update(id << 1, l, mid, x, v);
        if (x > mid)
            update(id << 1 | 1, mid + 1, r, x, v);

        t[id] = t[id << 1] + t[id << 1 | 1];
    }

    void query(int id, int l, int r, int ql, int qr, int v) {
        if (l > qr) {
            return;
        }

        if (t[id].m < v) {
            return;
        }

        if (l == r) {
            // cout << t[id].cur << endl;
            res = l;
            return;
        }

        int mid = (l + r) >> 1;

        if (t[id << 1].m >= v) {
            query(id << 1, l, mid, ql, qr, v);
        } else if (t[id << 1 | 1].m >= v) {
            query(id << 1 | 1, mid + 1, r, ql, qr, v);
        }
    }
} seg;

class BookMyShow {
public:
    vector<int> v;
    int n, m;
    FenwickTree<ll> t;
    int start;

    BookMyShow(int n, int m) {
        this->n = n;
        this->m = m;
        start = 1;

        v = vector<int>(n + 1, m);
        t.Init(n + 1);
        for (int i = 1; i <= n; i++) {
            t.Add(i, m);
        }

        seg.build(1, 1, n, m);
    }

    vector<int> gather(int k, int maxRow) {
        seg.res = -1;
        seg.query(1, 1, n, 1, maxRow + 1, k);

        int pos = seg.res;

        if (pos == -1) {
            return vector<int>();
        }

        // cout << pos << " " << v[pos] << endl;
        int h = m - v[pos];
        v[pos] -= k;
        t.Add(pos, -k);
        seg.update(1, 1, n, pos, -k);

        return vector<int>({pos - 1, h});
    }

    bool scatter(int k, int maxRow) {
        ll tot = t.Query(1, maxRow + 1);
        if (tot < k) {
            return false;
        }

        while (k > 0) {
            if (v[start] > k) {
                v[start] -= k;
                t.Add(start, -k);
                seg.update(1, 1, n, start, -k);
                break;
            } else {
                k -= v[start];
                t.Add(start, -v[start]);
                seg.update(1, 1, n, start, -v[start]);
                v[start] = 0;
                start++;
            }
        }

        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */

#ifdef LOCAL

int main() {
    return 0;
}

#endif
