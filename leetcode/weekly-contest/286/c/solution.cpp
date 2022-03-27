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

class Solution {
public:
    long long Max(int n) {
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = res * 10 + 9;
        }
        return res;
    }

    long long Min(int n) {
        long long res = 1;
        for (int i = 1; i < n; i++) {
            res *= 10;
        }
        return res;
    }

    long long Make(long long tar, int flag) {
        string s = to_string(tar);
        int len = s.length();
        for (int i = len - 1 - flag; i >= 0; i--) {
            s += s[i];
        }

        long long res = 0;
        for (int i = 0; i < s.length(); i++) {
            res = res * 10 + (s[i] - '0');
        }

        return res;
    }

    vector<long long> kthPalindrome(vector<int> &queries, int intLength) {
        int q = queries.size();
        auto res = vector<long long>(q, 0);
        for (int i = 0; i < q; i++) {
            int len = (intLength + 1) / 2;
            long long r = Max(len);
            long long l = Min(len);
            // cout << l << " " << r << endl;
            long long tot = (r - l + 1);
            if (queries[i] > tot) {
                res[i] = -1;
                continue;
            }

            long long tar = l + queries[i] - 1;
            res[i] = Make(tar, intLength & 1);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
