#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fi first
#define se second
#define all(x) begin(x), end(x)
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

class StockPrice {
public:
    StockPrice() {
        mp.clear();
        se.clear();
        max_timestamp_ = 0;
    }

    void update(int timestamp, int price) {
        if (mp.count(timestamp)) {
            if (price == mp[timestamp]) {
                return;
            }

            se.erase(se.find(mp[timestamp]));
        }

        mp[timestamp] = price;
        se.insert(price);

        chmax(max_timestamp_, timestamp);
    }

    int current() {
        return mp[max_timestamp_];
    }

    int maximum() {
        return *(se.rbegin());
    }

    int minimum() {
        return *(se.begin());
    }

private:
    int max_timestamp_{0};
    unordered_map<int, int> mp;
    multiset<int> se;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

#ifdef LOCAL

int main() {
    return 0;
}

#endif
