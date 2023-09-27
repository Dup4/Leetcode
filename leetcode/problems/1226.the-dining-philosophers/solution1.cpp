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

// [[0,1,1],[0,2,1],[0,0,3],[0,1,2],[2,1,1],[2,2,1],[2,0,3],[2,1,2],[2,2,2],[3,1,1],[3,2,1],[3,0,3],[3,1,2],[3,2,2],[4,1,1],[4,2,1],[4,0,3],[4,1,2],[4,2,2],[0,2,2],[1,1,1],[1,2,1],[1,0,3],[1,1,2],[1,2,2]]
// [[0,1,1],[0,2,1],[0,0,3],[0,1,2],[0,2,2],[2,1,1],[2,2,1],[1,1,1],[2,0,3],[2,1,2],[1,2,1],[4,1,1],[4,2,1],[2,2,2],[3,1,1],[1,0,3],[1,1,2],[1,2,2],[4,0,3],[4,1,2],[4,2,2],[3,2,1],[3,0,3],[3,1,2],[3,2,2]]
// [[0,1,1],[0,2,1],[0,0,3],[0,1,2],[0,2,2],[1,1,1],[1,2,1],[1,0,3],[1,1,2],[3,1,1],[3,2,1],[3,0,3],[3,1,2],[3,2,2],[4,1,1],[4,2,1],[4,0,3],[4,1,2],[4,2,2],[1,2,2],[2,1,1],[2,2,1],[2,0,3],[2,1,2],[2,2,2]]

enum class State {
    READY,
    HOLD_ONE,
    HOLD_TWO,
    AFTER_EAT,
};

class DiningPhilosophers {
public:
    DiningPhilosophers() {
        fork_state_ = vector<int>(n_, 0);
        mutex_list_ = vector<std::mutex>(n_);
        cond_list_ = vector<std::condition_variable>(n_);
    }

    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork,
            function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        int left_num = philosopher;
        int right_num = (philosopher + 1) % n_;

        if (left_num > right_num) {
            swap(left_num, right_num);
        }

        State s = State::READY;

        while (true) {
            if (s == State::READY) {
                std::invoke([&]() {
                    std::unique_lock<std::mutex> lock(mutex_list_[left_num]);

                    cond_list_[left_num].wait_for(lock, 100ms, [&]() {
                        return fork_state_[left_num] == 0;
                    });

                    if (fork_state_[left_num] == 1) {
                        return;
                    }

                    pickLeftFork();

                    fork_state_[left_num] = 1;
                    s = State::HOLD_ONE;
                });
            } else if (s == State::HOLD_ONE) {
                std::invoke([&]() {
                    std::unique_lock<std::mutex> lock(mutex_list_[right_num]);

                    cond_list_[right_num].wait_for(lock, 100ms, [&]() {
                        return fork_state_[right_num] == 0;
                    });

                    if (fork_state_[right_num] == 1) {
                        return;
                    }

                    fork_state_[right_num] = 1;
                    s = State::HOLD_TWO;
                    pickRightFork();

                    std::unique_lock<std::mutex> lock_left(mutex_list_[left_num]);

                    eat();

                    putLeftFork();
                    fork_state_[left_num] = 0;
                    cond_list_[left_num].notify_all();

                    putRightFork();
                    fork_state_[right_num] = 0;
                    cond_list_[right_num].notify_all();

                    s = State::AFTER_EAT;
                });

                std::invoke([&]() {
                    if (s != State::HOLD_ONE) {
                        return;
                    }

                    std::unique_lock<std::mutex> lock(mutex_list_[left_num]);

                    fork_state_[left_num] = 0;
                    putLeftFork();
                    s = State::READY;
                    cond_list_[left_num].notify_all();
                });

            } else if (s == State::HOLD_TWO) {
                std::unique_lock<std::mutex> lock(mutex_list_[left_num]);
                std::unique_lock<std::mutex> lock_right(mutex_list_[right_num]);

                eat();

                putLeftFork();
                fork_state_[left_num] = 0;
                cond_list_[left_num].notify_all();

                putRightFork();
                fork_state_[right_num] = 0;
                cond_list_[right_num].notify_all();

                // std::invoke([&]() {
                //     std::unique_lock<std::mutex> lock(mutex_list_[left_num]);

                // });

                // std::invoke([&]() {
                //     std::unique_lock<std::mutex> lock(mutex_list_[right_num]);

                // });

                break;
            } else if (s == State::AFTER_EAT) {
                break;
            }
        }
    }

private:
    std::vector<int> fork_state_{};
    std::vector<std::mutex> mutex_list_{};
    std::vector<std::condition_variable> cond_list_{};

    inline const static int n_ = 5;
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
