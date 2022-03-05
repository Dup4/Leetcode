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
inline bool chmax(T& a, const S& b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T& a, const S& b) {
    return a > b ? a = b, 1 : 0;
}

#ifdef LOCAL
#include <debug.hpp>
#else
#define dbg(...)
#endif
// head

struct node {
    int ix;
    int v;
    int w;
    bool operator<(const node& other) const {
        if (w != other.w) {
            return w < other.w;
        }

        return ix < other.ix;
    }
};

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<node> vec;

        auto f = [&](int x) {
            if (x == 0) {
                return mapping[0];
            }

            int res = 0;
            int base = 1;
            while (x) {
                res += mapping[x % 10] * base;
                x /= 10;
                base *= 10;
            }

            return res;
        };

        for (int i = 0; i < n; i++) {
            int a = nums[i];
            vec.emplace_back(node{
                    .ix = i,
                    .v = a,
                    .w = f(a),
            });
        }

        sort(vec.begin(), vec.end());

        vector<int> res;
        for (const auto& a : vec) {
            res.push_back(a.v);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
