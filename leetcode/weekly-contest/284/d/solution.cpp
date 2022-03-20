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

struct SEG {
    static const int N = 100005;

    struct node {
        int m, lazy;
        node() {
            m = lazy = 0;
        }

        void init() {
            m = lazy = 0;
        }

        void up(int x) {
            m += x;
            lazy += x;
        }

        node operator+(const node &other) const {
            node res = node();
            res.m = max(m, other.m);
            return res;
        }
    } t[N << 2], res;

    // vector<node> t;
    // node res;

    // SEG() {
    //     t = vector<node>(N << 2, node());
    //     res.init();
    // }

    void down(int id) {
        int &lazy = t[id].lazy;
        t[id << 1].up(lazy);
        t[id << 1 | 1].up(lazy);
        lazy = 0;
    }

    void build(int id, int l, int r, const vector<int> &a) {
        t[id] = node();
        if (l > r) {
            return;
        }
        if (l == r) {
            t[id].m = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, a);
        build(id << 1 | 1, mid + 1, r, a);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }

    void update(int id, int l, int r, int ql, int qr, int v) {
        if (ql > qr) {
            return;
        }

        if (l >= ql && r <= qr) {
            t[id].up(v);
            return;
        }
        int mid = (l + r) >> 1;
        down(id);
        if (ql <= mid)
            update(id << 1, l, mid, ql, qr, v);
        if (qr > mid)
            update(id << 1 | 1, mid + 1, r, ql, qr, v);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }

    void query(int id, int l, int r, int ql, int qr) {
        if (ql > qr) {
            return;
        }

        // cout << l << " " << r << " " << ql << " " << qr << endl;
        if (l >= ql && r <= qr) {
            res = res + t[id];
            return;
        }
        int mid = (l + r) >> 1;
        down(id);
        if (ql <= mid)
            query(id << 1, l, mid, ql, qr);
        if (qr > mid)
            query(id << 1 | 1, mid + 1, r, ql, qr);
    }

    int query(int n, int ix) {
        if (ix > n) {
            return 0;
        }

        if (ix < 0) {
            return 0;
        }

        res.init();
        query(1, 1, n, ix, ix);
        return res.m;
    }

    void setZero(int n, int ix) {
        int x = query(n, ix);
        update(1, 1, n, ix, ix, -x);
    }
};

SEG pre_seg, nx_seg;

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices) {
        int n = s.length();
        s.insert(0, "@");
        s.push_back('@');

        vector<int> pre(n + 5, 0), nx(n + 5, 0);

        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            char c = s[i];
            char prec = s[i - 1];
            if (c == prec) {
                pre[i] = pre[i - 1] + 1;
            } else {
                pre[i] = 1;
            }
        }

        nx[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            char c = s[i];
            char nxc = s[i + 1];
            if (c == nxc) {
                nx[i] = nx[i + 1] + 1;
            } else {
                nx[i] = 1;
            }
        }

        // pre_seg.init(n);
        // nx_seg.init(n);
        pre_seg.build(1, 1, n, pre);
        nx_seg.build(1, 1, n, nx);

        vector<int> res;

        int k = queryCharacters.length();
        for (int i = 0; i < k; i++) {
            int ix = queryIndices[i] + 1;
            char change_c = queryCharacters[i];
            char ori_c = s[ix];
            char pre_c = s[ix - 1];
            char nx_c = s[ix + 1];
            s[ix] = change_c;

            if (change_c != ori_c) {
                {
                    int cur_pre = pre_seg.query(n, ix);
                    int cur_nx = nx_seg.query(n, ix);
                    nx_seg.update(1, 1, n, ix - cur_pre + 1, ix - 1, -cur_nx);
                    pre_seg.update(1, 1, n, ix + 1, ix + cur_nx - 1, -cur_pre);
                }

                pre_seg.setZero(n, ix);
                nx_seg.setZero(n, ix);

                {
                    int ccur_pre = pre_seg.query(n, ix - 1);
                    int ccur_nx = nx_seg.query(n, ix + 1);
                    int cur_pre = 1;
                    int cur_nx = 1;

                    if (change_c == pre_c) {
                        cur_pre += ccur_pre;
                    }

                    if (change_c == nx_c) {
                        cur_nx += ccur_nx;
                    }

                    nx_seg.update(1, 1, n, ix - cur_pre + 1, ix, cur_nx);
                    pre_seg.update(1, 1, n, ix, ix + cur_nx - 1, cur_pre);
                }
            }

            pre_seg.res.init();
            pre_seg.query(1, 1, n, 1, n);
            res.push_back(pre_seg.res.m);

            // vector<int> pre, nx;
            // for (int i = 1; i <= n; i++) {
            //     pre.push_back(pre_seg.query(n, i));
            //     nx.push_back(nx_seg.query(n, i));
            // }
            // dbg(pre);
            // dbg(nx);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    {
        auto s = new Solution();
        auto v = vector<int>({2, 1});
        auto ans = s->longestRepeating("abyzz", "aa", v);
        dbg(ans);
    }

    {
        auto s = new Solution();
        auto v = vector<int>({1, 3, 3});
        auto ans = s->longestRepeating("babacc", "bcb", v);
        dbg(ans);
    }
    return 0;
}

#endif
