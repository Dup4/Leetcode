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
    string bestHand(vector<int> &ranks, vector<char> &suits) {
        {
            bool Flush = true;

            for (int i = 1; i < 5; i++) {
                if (suits[i] != suits[0]) {
                    Flush = false;
                    break;
                }
            }

            if (Flush) {
                return "Flush";
            }
        }

        sort(all(ranks));

        for (int i = 2; i < 5; i++) {
            if (ranks[i] == ranks[i - 1] && ranks[i] == ranks[i - 2]) {
                return "Three of a Kind";
            }
        }

        for (int i = 1; i < 5; i++) {
            if (ranks[i] == ranks[i - 1]) {
                return "Pair";
            }
        }

        return "High Card";
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
