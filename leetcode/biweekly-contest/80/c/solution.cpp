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
    bool matchReplacement(string s, string sub, vector<vector<char>> &mappings) {
        map<char, std::string> mp;

        for (int i = 'a'; i <= 'z'; i++) {
            mp[char(i)] = string(1, char(i));
        }

        for (int i = 'A'; i <= 'Z'; i++) {
            mp[char(i)] = string(1, char(i));
        }

        for (int i = '0'; i <= '9'; i++) {
            mp[char(i)] = string(1, char(i));
        }

        for (auto &mapping : mappings) {
            mp[mapping[0]] += mapping[1];
        }

        for (auto &[k, v] : mp) {
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }

        int n = int(s.length());
        int m = int(sub.length());

        for (int i = 0; i < n; i++) {
            if (i + m > n) {
                break;
            }

            bool ok = 1;

            for (int j = 0; j < m; j++) {
                if (mp[sub[j]].find(s[i + j]) == string::npos) {
                    ok = 0;
                    break;
                }
            }

            if (ok) {
                return true;
            }
        }

        return false;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
