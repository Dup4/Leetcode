#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>

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

struct node {
    int ix;
    ll t;
    bool operator<(const node &other) const {
        if (t == other.t) {
            return ix > other.ix;
        }

        return t > other.t;
    }
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        int m = int(meetings.size());
        sort(all(meetings));

        // cout << "meetings" << endl;
        // for (int i = 0; i < m; i++) {
        //     cout << meetings[i][0] << " " << meetings[i][1] << endl;
        // }

        auto f = vector<int>(n, 0);
        // auto tm = vector<int>(n, 0);

        auto pq = priority_queue<node>();
        for (int i = 0; i < n; i++) {
            pq.push(node{
                    .ix = i,
                    .t = 0,
            });
        }

        for (int i = 0; i < m; i++) {
            int dur = meetings[i][1] - meetings[i][0];
            ll st = meetings[i][0];

            while (!pq.empty() && pq.top().t < st) {
                auto top = pq.top();
                pq.pop();
                top.t = st;
                pq.push(top);
            }

            auto top = pq.top();
            pq.pop();

            st = max(st, top.t);
            ++f[top.ix];

            top.t = st + dur;
            pq.push(top);
        }

        int mm = 0;
        int ix = 0;
        // cout << "f" << endl;
        for (int i = 0; i < n; i++) {
            // cout << i << " " << f[i] << endl;
            if (f[i] > mm) {
                mm = f[i];
                ix = i;
            }
        }

        return ix;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
