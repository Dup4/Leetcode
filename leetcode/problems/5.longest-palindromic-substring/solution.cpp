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

struct Manacher {
    int len, l;
    char Ma[N << 1];
    int Mp[N << 1];
    void work(const char *s) {
        len = strlen(s);
        l = 0;
        Ma[l++] = '$';
        Ma[l++] = '#';
        for (int i = 0; i < len; ++i) {
            Ma[l++] = s[i];
            Ma[l++] = '#';
        }
        Ma[l] = 0;
        int mx = 0, id = 0;
        for (int i = 0; i < l; ++i) {
            Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;
            while ((i - Mp[i]) >= 0 && Ma[i + Mp[i]] == Ma[i - Mp[i]]) Mp[i]++;
            if (i + Mp[i] > mx) {
                mx = i + Mp[i];
                id = i;
            }
        }
    }
    bool check(int l, int r) {
        int il = (l + 1) * 2, ir = (r + 1) * 2;
        int mid = (il + ir) / 2;
        int len = (r - l + 2) / 2;
        return (Mp[mid] / 2) >= len;
    }
} man;

class Solution {
public:
    string longestPalindrome(string s) {
        man.work(s.c_str());

        for (int i = s.length(); i >= 1; i--) {
            for (int j = s.length() - i; j >= 0; j--) {
                if (man.check(j, j + i - 1)) {
                    return s.substr(j, i);
                }
            }
        }

        return 0;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
