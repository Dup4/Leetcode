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

class Allocator {
public:
    vector<int> mem;
    int n;

    Allocator(int n) {
        this->n = n;
        mem = vector<int>(n + 5, 0);
    }

    int allocate(int size, int mID) {
        for (int i = 0; i < n && i + size <= n; i++) {
            if (mem[i] != 0) {
                continue;
            }

            int ok = 1;

            for (int j = i; j - i < size; j++) {
                if (mem[j] != 0) {
                    i = j;
                    ok = 0;
                    break;
                }
            }

            if (ok) {
                for (int j = i; j - i < size; j++) {
                    mem[j] = mID;
                }

                return i;
            }
        }

        return -1;
    }

    int free(int mID) {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (mem[i] == mID) {
                mem[i] = 0;
                ++cnt;
            }
        }

        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

#ifdef LOCAL

int main() {
    return 0;
}

#endif
