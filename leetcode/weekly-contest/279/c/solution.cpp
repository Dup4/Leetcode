#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fi first
#define se second
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

class Bitset {
public:
    vector<bool> bit;
    int f;
    int cnt[2];
    int n;

    Bitset(int size) {
        bit = vector<bool>(size, 0);
        cnt[0] = size;
        cnt[1] = 0;
        n = size;
        f = 0;
    }

    void fix(int idx) {
        --cnt[bit[idx]];
        bit[idx] = f ^ 1;
        ++cnt[bit[idx]];
    }

    void unfix(int idx) {
        --cnt[bit[idx]];
        bit[idx] = f;
        ++cnt[bit[idx]];
    }

    void flip() {
        f ^= 1;
    }

    bool all() {
        return cnt[f ^ 1] == n;
    }

    bool one() {
        return bool(cnt[f ^ 1] > 0);
    }

    int count() {
        return cnt[f ^ 1];
    }

    string toString() {
        string res = "";
        for (int i = 0; i < n; i++) {
            res += (bit[i] ^ f) + '0';
        }

        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

#ifdef LOCAL

int main() {
    return 0;
}

#endif
