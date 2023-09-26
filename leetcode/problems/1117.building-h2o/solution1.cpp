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

class H2O {
public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        while (release_h_ <= 0) {
            std::this_thread::yield();
        }

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        release_h_--;
        ++print_h_;

        if (print_h_ % 2 == 0) {
            release_o_.fetch_add(1);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        while (release_o_ <= 0) {
            std::this_thread::yield();
        }

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        release_o_--;
        ++print_o_;

        release_h_.fetch_add(2);
    }

private:
    std::atomic<int> print_h_{0};
    std::atomic<int> print_o_{0};
    std::atomic<int> release_h_{2};
    std::atomic<int> release_o_{1};
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
