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

template <typename T = int>
class Hash {
public:
    Hash() = default;
    ~Hash() {}

    // You need to make sure the `x` passed in is valid,
    // otherwise it will cause a runtime error.
    T &operator[](int x) const {
        return vec_[x - 1];
    }

    void Init() {
        vec_.clear();
    }

    void Init(int n) {
        Init();
        vec_.reserve(n);
    }

    int Size() const {
        return vec_.size();
    }

    void Add(const T &x) {
        vec_.push_back(x);
    }

    T Get(const T &x) const {
        return lower_bound(vec_.begin(), vec_.end(), x) - vec_.begin() + 1;
    }

    const std::vector<T> &GetVec() const {
        return vec_;
    }

    // After you have added all the <T> that need to be discretized,
    // don't forget to call this function to deduplicate.
    void Gao() {
        sort(vec_.begin(), vec_.end());
        vec_.erase(unique(vec_.begin(), vec_.end()), vec_.end());
    }

private:
    std::vector<T> vec_;
};

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

Hash h;
FenwickTree<int> t;

// nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
// nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff

class Solution {
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff) {
        int n = int(nums1.size());

        h.Init(n * 2 + 10);

        ll res = 0;
        auto f = vector<int>();

        for (int i = 0; i < n; i++) {
            f.push_back(nums1[i] - nums2[i]);
            h.Add(f.back());
            h.Add(f.back() + diff);
        }

        h.Gao();

        t.Init(h.Size() + 5);
        t.Add(h.Get(f[0]), 1);

        for (int i = 1; i < n; i++) {
            res += t.Query(0, h.Get(f[i] + diff));
            t.Add(h.Get(f[i]), 1);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
