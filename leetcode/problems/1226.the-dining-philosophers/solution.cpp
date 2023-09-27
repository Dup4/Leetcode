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
    UNKNOWN,
    READY,
    HOLD_ONE,
    HOLD_TWO,
    AFTER_EAT,
    PUT_ONE,
};

struct Node {
    int left_num{0};
    int right_num{0};
    bool hold_left{false};
    bool hold_right{false};
    State state{State::READY};
};

class DiningPhilosophers {
public:
    DiningPhilosophers() {
        node_ = vector<Node>(n_);
        fork_state_ = vector<int>(n_, 0);

        for (int i = 0; i < n_; i++) {
            auto &node = node_[i];
            node.left_num = i;
            node.right_num = (i + 1) % n_;
        }
    }

    void wantsToEat(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork,
            function<void()> eat, function<void()> putLeftFork, function<void()> putRightFork) {
        auto &node = node_[philosopher];

        std::unique_lock<std::mutex> lock(mutex_);

        if (node.state == State::READY) {
            if (fork_state_[node.left_num] == 0) {
                fork_state_[node.left_num] = 1;
                node.hold_left = true;
                node.state = State::HOLD_ONE;
                pickLeftFork();
            } else if (fork_state_[node.right_num] == 0) {
                fork_state_[node.right_num] = 1;
                node.hold_right = true;
                node.state = State::HOLD_ONE;
                pickRightFork();
            }
        } else if (node.state == State::HOLD_ONE) {
            if (node.hold_left) {
                if (fork_state_[node.right_num] == 0) {
                    fork_state_[node.right_num] = 1;
                    node.hold_right = true;
                    node.state = State::HOLD_TWO;
                    pickRightFork();
                } else {
                    fork_state_[node.left_num] = 0;
                    node.hold_left = false;
                    node.state = State::READY;
                    putLeftFork();
                }
            } else {
                if (fork_state_[node.left_num] == 0) {
                    fork_state_[node.left_num] = 1;
                    node.hold_left = true;
                    node.state = State::HOLD_TWO;
                    pickLeftFork();
                } else {
                    fork_state_[node.right_num] = 0;
                    node.hold_right = false;
                    node.state = State::READY;
                    pickRightFork();
                }
            }
        } else if (node.state == State::HOLD_TWO) {
            node.state = State::AFTER_EAT;
            eat();
        } else if (node.state == State::AFTER_EAT) {
            fork_state_[node.right_num] = 0;
            node.hold_right = false;
            node.state = State::PUT_ONE;
            putRightFork();
        } else if (node.state == State::PUT_ONE) {
            fork_state_[node.left_num] = 0;
            node.hold_left = false;
            node.state = State::READY;
            putLeftFork();
        }
    }

private:
    vector<Node> node_{};
    std::vector<int> fork_state_{};
    std::mutex mutex_{};

    inline const static int n_ = 5;
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
