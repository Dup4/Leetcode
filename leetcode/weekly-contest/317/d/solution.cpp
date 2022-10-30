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

struct node {
    int left_h = 0;
    int right_h = 0;
    int deep = 0;
};

class Solution {
public:
    map<int, int> res;
    map<int, node> tree_info;
    int n;
    int max_height;

    int preDFS(TreeNode *root, int deep) {
        ++n;

        int val = root->val;
        auto &ti = tree_info[val];

        ti.deep = deep;
        max_height = max(max_height, deep);

        if (root->left) {
            ti.left_h = preDFS(root->left, deep + 1) + 1;
        }

        if (root->right) {
            ti.right_h = preDFS(root->right, deep + 1) + 1;
        }

        return max(ti.left_h, ti.right_h);
    }

    void dfs(TreeNode *root, int mmax_height) {
        int val = root->val;

        const auto &ti = tree_info[val];
        if (ti.left_h == ti.right_h) {
            return;
        }

        if (ti.left_h > ti.right_h) {
            int height = max(ti.deep + ti.right_h, mmax_height);
            res[root->left->val] = height;
            dfs(root->left, height);
        } else {
            int height = max(ti.deep + ti.left_h, mmax_height);
            res[root->right->val] = height;
            dfs(root->right, height);
        }
    }

    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        res.clear();
        tree_info.clear();

        n = 0;
        max_height = 0;

        preDFS(root, 0);
        dfs(root, -1);

        // cout << max_hight << endl;

        auto ans = vector<int>();
        for (const auto &q : queries) {
            if (res.count(q)) {
                ans.push_back(res[q]);
            } else {
                ans.push_back(max_height);
            }
        }

        return ans;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
