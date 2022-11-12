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

const int N = 1e4 + 10;

class Solution {
public:
    bool has_init = false;
    int f[N], g[N];

    void init() {
        f[0] = 0;
        for (int i = 1; i < N; i++) {
            int len = int(to_string(i).size());

            f[i] = f[i - 1] + len;
            g[i] = f[i] + (3 + len) * i;
        }
    }

    vector<string> splitMessage(string message, int limit) {
        if (has_init == false) {
            init();
            has_init = true;
        }

        int n = int(message.size());
        int res = -1;

        for (int i = max(1, n / limit); i < N; i++) {
            int high = limit * i - g[i];
            int low = (limit * (i - 1)) - g[i] + (int(to_string(i).size()) * 2 + 3);

            // cout << i << " " << low << " " << high << endl;

            if (n >= low && n <= high) {
                res = i;
                break;
            }
        }

        if (res == -1) {
            return vector<string>();
        }

        {
            reverse(all(message));
            auto ans = vector<string>();

            for (int i = 1; i <= res; i++) {
                string tmp = "<";
                tmp += to_string(i);
                tmp += "/";
                tmp += to_string(res);
                tmp += ">";

                string ttmp = "";
                int remind = int(limit - tmp.size());
                while (!message.empty() && remind) {
                    --remind;
                    ttmp += message.back();
                    message.pop_back();
                }

                ttmp += tmp;
                ans.push_back(ttmp);
            }

            return ans;
        }
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
