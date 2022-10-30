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

class Solution {
public:
    int getTarget(ll n) {
        int res = 0;

        while (n) {
            res += n % 10;
            n /= 10;
        }

        return res;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        auto vec = vector<int>();

        ll _n = n;
        while (_n) {
            vec.push_back(_n % 10);
            _n /= 10;
        }

        vec.push_back(0);

        int sze = int(vec.size());

        // for (int i = 0; i < sze; i++) {
        //     cout << i << " " << vec[i] << endl;
        // }

        for (int i = 0; i < sze - 1; i++) {
            int sum = accumulate(all(vec), 0);
            if (sum <= target) {
                break;
            }

            vec[i] = 0;
            ++vec[i + 1];

            for (int j = i + 1; j < sze - 1; j++) {
                if (vec[j] < 10) {
                    break;
                }
                vec[j] = 0;
                ++vec[j + 1];
            }
        }

        // while (!vec.empty() && vec.back() == 0) {
        //     vec.pop_back();
        // }

        reverse(all(vec));

        ll m = 0;
        for (const auto &a : vec) {
            m = m * 10 + a;
        }

        return m - n;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
