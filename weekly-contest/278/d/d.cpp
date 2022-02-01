#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define rall rbegin(a), rend(a)
#define lowbit(x) ((x) & (-(x)))
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

const int N = 1e5 + 5;

struct UFS {
    int fa[N], rk[N], sze[N];
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = 0;
            rk[i] = 0;
            sze[i] = 1;
        }
    }

    int find(int x) {
        return fa[x] == 0 ? x : fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            if (rk[fx] > rk[fy]) {
                swap(fx, fy);
            }

            fa[fx] = fy;
            sze[fy] += sze[fx];
            if (rk[fx] == rk[fy]) {
                ++rk[fy];
            }

            return true;
        }
        return false;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
} ufs;

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        constexpr auto f = [](string& s) {
            ll res = 0;
            for (auto& c : s) {
                res |= 1ll << (c - 'a');
            }

            return res;
        };

        int n = words.size();
        ufs.init(n + 1);

        unordered_map<ll, int> mp;
        vector<ll> vec;
        vec.reserve(n);

        for (int i = 0; i < n; i++) {
            ll a = f(words[i]);
            vec.push_back(a);
            if (mp.count(a)) {
                ufs.merge(mp[a] + 1, i + 1);
            } else {
                mp[a] = i;
            }
        }

        for (int i = 0; i < n; i++) {
            ll a = vec[i];
            if (mp[a] != i) {
                continue;
            }

            for (int j = 0; j < 26; j++) {
                ll b = (a ^ (1ll << j));
                if (mp.count(b)) {
                    ufs.merge(i + 1, mp[b] + 1);
                }

                if ((a >> j) & 1) {
                    ll _a = a ^ (1ll << j);
                    for (int k = 0; k < 26 && k != j; k++) {
                        if (((_a >> k) & 1) == 0) {
                            ll c = (_a ^ (1ll << k));
                            if (mp.count(c)) {
                                ufs.merge(i + 1, mp[c] + 1);
                            }
                        }
                    }
                }
            }
        }

        int cnt = 0, Max = 0;
        for (int i = 0; i < n; i++) {
            if (ufs.find(i + 1) == i + 1) {
                ++cnt;
                chmax(Max, ufs.sze[i + 1]);
            }
        }

        return vector<int>{cnt, Max};
    }
};

#ifdef LOCAL

int main() {
    auto s = Solution();
    {
        auto sv = vector<string>{"a", "b", "ab", "cde"};
        auto ans = s.groupStrings(sv);
        dbg(ans);
    }

    {
        auto sv = vector<string>{"web", "a", "te", "hsx", "v", "k", "a", "roh"};
        auto ans = s.groupStrings(sv);
        dbg(ans);
    }

    return 0;
}

#endif
