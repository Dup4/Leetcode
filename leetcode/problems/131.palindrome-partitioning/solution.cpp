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

class Solution {
public:
    bool check(const string& s) {
        string t = s;
        reverse(all(t));
        return s == t;
    }

    bool checkAll(const vector<string>& ss) {
        for (const auto& s : ss) {
            if (!check(s)) {
                return false;
            }
        }

        return true;
    }

    void dfs(const string& s, int ix, string t, vector<string> cur, vector<vector<string>>& res) {
        if (ix == s.length()) {
            if (!t.empty()) {
                return;
            }

            if (checkAll(cur)) {
                res.push_back(cur);
            }

            return;
        }

        t += s[ix];
        dfs(s, ix + 1, t, cur, res);

        cur.push_back(t);
        dfs(s, ix + 1, "", cur, res);
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;

        dfs(s, 0, "", vector<string>(), res);

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
