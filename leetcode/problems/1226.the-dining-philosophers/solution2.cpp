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

enum class State {
    READY,
    HOLD_ONE,
    HOLD_TWO,
};

class DiningPhilosophers {
public:
    DiningPhilosophers() {
        mutex_list_ = vector<std::mutex>(n_);
    }

    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork,
            function<void()> eat, function<void()> putLeftFork, [[maybe_unused]] function<void()> putRightFork) {
        int left_num = philosopher;
        int right_num = (philosopher + 1) % n_;

        if (left_num > right_num) {
            swap(left_num, right_num);
        }

        std::unique_lock<std::mutex> lock_left(mutex_list_[left_num]);
        std::unique_lock<std::mutex> lock_right(mutex_list_[right_num]);

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }

private:
    std::vector<std::mutex> mutex_list_{};

    inline const static int n_ = 5;
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
