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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#ifdef LOCAL
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
public:
    vector<vector<int>> vec;
    int max_depth = 0;
    void getMaxDepth(TreeNode *rt, int deep) {
        if (!rt) {
            return;
        }

        max_depth = max(max_depth, deep);
        getMaxDepth(rt->left, deep + 1);
        getMaxDepth(rt->right, deep + 1);
    }

    void dfs(TreeNode *rt, int deep) {
        if (!rt) {
            return;
        }

        vec[deep].push_back(rt->val);
        dfs(rt->left, deep + 1);
        dfs(rt->right, deep + 1);
    }

    int getMinSwaps(const vector<int> &A) {
        vector<int> B(A);
        sort(B.begin(), B.end());
        map<int, int> m;
        int len = (int)A.size();
        for (int i = 0; i < len; i++) {
            m[B[i]] = i;
        }
        int loops = 0;
        vector<bool> flag(len, false);
        for (int i = 0; i < len; i++) {
            if (!flag[i]) {
                int j = i;
                while (!flag[j]) {
                    flag[j] = true;
                    j = m[A[j]];
                }
                loops++;
            }
        }
        return len - loops;
    }

    int minimumOperations(TreeNode *root) {
        max_depth = 0;
        getMaxDepth(root, 1);
        vec = vector<vector<int>>(max_depth + 5, vector<int>());
        dfs(root, 0);

        int res = 0;
        for (const auto &v : vec) {
            res += getMinSwaps(v);
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
