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
    int idx;
    map<string, int> id_map;
    int getId(const std::string &s) {
        if (id_map.count(s) == 0) {
            id_map[s] = ++idx;
        }

        return id_map[s];
    }

    long long distinctNames(vector<string> &ideas) {
        idx = 0;
        id_map = {};

        int n = int(ideas.size());
        ll res = 1ll * n * n;

        vector<int> id(n);
        vector<int> first_char(n);

        for (int i = 0; i < n; i++) {
            id[i] = getId(ideas[i].substr(1));
            first_char[i] = ideas[i][0] - 'a';
        }

        map<int, bitset<26>> mp;
        vector<int> cnt(26, 0);
        vector<vector<int>> fcnt(26, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            mp[id[i]].set(first_char[i]);
            ++cnt[first_char[i]];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (mp[id[i]].test(j)) {
                    ++fcnt[j][first_char[i]];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (mp[id[i]].test(j)) {
                    res -= cnt[j];
                } else {
                    res -= fcnt[first_char[i]][j];
                }
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
