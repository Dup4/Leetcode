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

const int N = 3e4 + 10;

struct UFS {
    int fa[N];
    unordered_map<int, int> mp[N];

    void init(int n) {
        for (int i = 0; i <= n; i++) {
            fa[i] = 0;
            mp[i].clear();
        }
    }

    int find(int x) {
        return fa[x] == 0 ? x : fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            fa[fx] = fy;

            for (const auto &[k, v] : mp[fx]) {
                mp[fy][k] += v;
            }

            return true;
        }

        return false;
    }
} ufs;

class Solution {
public:
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
        int n = int(vals.size());

        ufs.init(n);

        auto node = vector<pair<int, int>>();
        for (int i = 0; i < n; i++) {
            node.push_back(make_pair(vals[i], i + 1));
        }

        auto graph = vector<vector<int>>(n + 5, vector<int>());

        for (const auto &e : edges) {
            graph[e[0] + 1].push_back(e[1] + 1);
            graph[e[1] + 1].push_back(e[0] + 1);
        }

        auto ok_node = vector<int>(n + 1, 0);

        int res = 0;

        sort(all(node));

        for (int i = 0; i < n; i++) {
            int _val = node[i].first;
            int r = i;

            for (int j = i; j < n; j++) {
                int val = node[j].first;
                if (val != _val) {
                    break;
                }

                int u = node[j].second;

                r = j;

                ok_node[u] = 1;
                ufs.mp[u][val] = 1;

                for (const auto &v : graph[u]) {
                    if (ok_node[v]) {
                        ufs.merge(u, v);
                    }
                }
            }

            for (int j = i; j <= r; j++) {
                int val = node[j].first;
                int u = node[j].second;

                int rt = ufs.find(u);
                auto &mp = ufs.mp[rt];

                int tot = mp[val];
                res += tot;
            }

            i = r;
        }

        res -= (res - n) / 2;

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
