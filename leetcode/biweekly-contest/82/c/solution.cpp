#include <bits/stdc++.h>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <queue>
#include <vector>

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
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2) {
        int n = (int)(nums1.size());

        vector<int> f;
        f.reserve(n);
        for (int i = 0; i < n; i++) {
            f.push_back(abs(nums1[i] - nums2[i]));
        }
        f.push_back(0);
        sort(all(f));

        priority_queue<int, vector<int>, less<int>> pq;

        ll k = k1 + k2;

        int cnt = 1;
        ll num = f[n];
        for (int i = n - 1; i >= 0; i--) {
            ll c = (num - f[i]) * cnt;

            if (k >= c) {
                k -= c;
                ++cnt;
                num = f[i];
            } else {
                ll x = k / cnt;
                num -= x;
                k -= x * cnt;

                for (int j = 0; j <= i; j++) {
                    pq.push(f[j]);
                }

                for (int j = 1; j <= cnt; j++) {
                    pq.push(int(num));
                }

                break;
            }
        }

        if (cnt == n + 1) {
            for (int j = 1; j <= cnt; j++) {
                pq.push(int(num));
            }
        }

        while (k && !pq.empty()) {
            auto t = pq.top();
            pq.pop();

            if (t > 0) {
                pq.push(t - 1);
                k--;
            }
        }

        ll res = 0;
        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();

            res += 1ll * x * x;
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
