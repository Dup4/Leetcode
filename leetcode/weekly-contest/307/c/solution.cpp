#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>

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
    map<int, vector<int>> G;
    int max_dep;

    void dfs(TreeNode *root) {
        if (!root) {
            return;
        }

        if (root->left) {
            G[root->val].push_back(root->left->val);
            G[root->left->val].push_back(root->val);
            dfs(root->left);
        }

        if (root->right) {
            G[root->val].push_back(root->right->val);
            G[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }

    void dfs2(int root, int fa, int dep) {
        // cout << root << endl;

        max_dep = max(max_dep, dep);

        for (const auto &u : G[root]) {
            if (u == fa) {
                continue;
            }

            dfs2(u, root, dep + 1);
        }
    }

    int amountOfTime(TreeNode *root, int start) {
        G.clear();
        max_dep = 0;
        dfs(root);
        dfs2(start, start, 0);
        return max_dep;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
