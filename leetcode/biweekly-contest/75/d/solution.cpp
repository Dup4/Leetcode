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

const int N = 1e5 + 10;

struct ExKMP {
    int Next[N];
    void GetNext(const char *s) {
        int lens = strlen(s + 1), p = 1, pos;
        Next[1] = lens;
        while (p + 1 <= lens && s[p] == s[p + 1]) ++p;
        Next[pos = 2] = p - 1;
        for (int i = 3; i <= lens; ++i) {
            int len = Next[i - pos + 1];
            if (len + i < p + 1)
                Next[i] = len;
            else {
                int j = max(p - i + 1, 0);
                while (i + j <= lens && s[j + 1] == s[i + j]) ++j;
                p = i + (Next[pos = i] = j) - 1;
            }
        }
    }
} exkmp;

class Solution {
public:
    long long sumScores(string s) {
        s.insert(0, "@");
        exkmp.GetNext(s.c_str());

        ll res = 0;

        for (int i = 1; i < s.length(); i++) {
            // cout << i << " " << exkmp.Next[i] << endl;
            res += exkmp.Next[i];
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
