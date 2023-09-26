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

class Foo {
public:
    Foo() {}

    void first(function<void()> printFirst) {
        while (order_.load() % 3 != 0) {
            std::this_thread::yield();
        }

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        order_++;
    }

    void second(function<void()> printSecond) {
        while (order_.load() % 3 != 1) {
            std::this_thread::yield();
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        order_++;
    }

    void third(function<void()> printThird) {
        while (order_.load() % 3 != 2) {
            std::this_thread::yield();
        }

        // printThird() outputs "third". Do not change or remove this line.
        printThird();

        order_++;
    }

private:
    std::atomic<int> order_{0};
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
