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

class Manacher {
public:
    Manacher() {}

    Manacher(const int n) {
        fake_s_.reserve(n << 1);
        u.reserve(n << 1);
    }

    ~Manacher() {}

    // 0-index
    void Build(const char *s, size_t len) {
        this->len = static_cast<int>(len);
        fake_s_.resize((len + 1) << 2);
        u.resize((len + 1) << 2);

        l = 0;

        fake_s_[l++] = '$';
        fake_s_[l++] = '#';
        for (size_t i = 0; i < len; i++) {
            fake_s_[l++] = s[i];
            fake_s_[l++] = '#';
        }
        fake_s_[l] = 0;

        int mx = 0, id = 0;
        for (int i = 0; i < l; i++) {
            u[i] = mx > i ? std::min(u[2 * id - i], mx - i) : 1;

            while (i - u[i] >= 0 && fake_s_[i + u[i]] == fake_s_[i - u[i]]) {
                u[i]++;
            }

            if (i + u[i] > mx) {
                mx = i + u[i];
                id = i;
            }
        }

        fake_s_.resize(l);
        u.resize(l);
    }

    void Build(const char *s) {
        Build(s, strlen(s));
    }

    void Build(const std::string &s) {
        Build(s.c_str(), s.length());
    }

    // check if s[l:r + 1] is a palindrome.
    bool IsPalindrome(int l, int r) const {
        int il = (l + 1) * 2, ir = (r + 1) * 2;
        int mid = (il + ir) / 2;
        int len = (r - l + 2) / 2;
        return (u[mid] / 2) >= len;
    }

    // get the length of the longest palindrome substring
    int GetMaxLengthOfPalindromeSubstring() const {
        int res = 0;

        for (int i = 0; i < l; i++) {
            res = std::max(res, u[i] - 1);
        }

        return res;
    }

    const std::vector<int> &GetU() {
        return u;
    }

private:
    int len, l;
    std::vector<char> fake_s_;
    std::vector<int> u;
};

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = int(s.size());
        auto m = Manacher(n + 5);

        m.Build(s);

        auto f = vector<int>(n + 5, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i - k + 1; j >= 1; j--) {
                if (m.IsPalindrome(j - 1, i - 1)) {
                    f[i] = max(f[i], f[j - 1] + 1);
                }
            }

            f[i] = max(f[i], f[i - 1]);
        }

        return f[n];
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
