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

class ATM {
public:
    vector<ll> v;
    vector<int> f;
    ATM() {
        v = vector<ll>(10, 0);
        f = vector<int>({20, 50, 100, 200, 500});
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            v[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        auto res = vector<int>(5, 0);
        int remind = amount;
        for (int i = 4; i >= 0; i--) {
            ll cur = min<ll>(v[i], remind / f[i]);
            res[i] = cur;
            remind -= f[i] * cur;
        }

        if (remind != 0) {
            return vector<int>({-1});
        }

        for (int i = 0; i < 5; i++) {
            v[i] -= res[i];
        }

        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */

#ifdef LOCAL

int main() {
    return 0;
}

#endif
