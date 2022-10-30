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

struct node {
    ll sum = 0;
    int max_view = -1;
    string id = "";
};

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views) {
        int n = int(creators.size());

        auto mp = map<string, node>();
        ll mx_views = 0;

        for (int i = 0; i < n; i++) {
            const auto &c = creators[i];
            const auto &id = ids[i];
            int view = views[i];

            mp[c].sum += view;
            if (view > mp[c].max_view || (view == mp[c].max_view && id < mp[c].id)) {
                mp[c].max_view = view;
                mp[c].id = id;
            }

            mx_views = max(mx_views, mp[c].sum);
        }

        auto res = vector<vector<string>>();
        for (const auto &[k, v] : mp) {
            if (v.sum == mx_views) {
                res.push_back(vector<string>({k, v.id}));
            }
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
