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

// 1 2 3 4 5 6
// 1 6 3 4 5 2
// 1 3 6 4 5 2
// 1 3 4 6 5 2
// 1 3 4 5 6 2
// 1 3 4 5 2 6
// 1 3 4 2 5 6
// 1 3 2 4 5 6
// 1 2 3 4 5 6

// 3 2 1
// 1 2 3

// 1 3 2 4
// 1 2 3 4

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
    void dfs(TreeNode *root) {
        if (root->left) {
            dfs(root->left);
        }

        if (pre_) {
            if (root->val < pre_->val) {
                if (first_ == nullptr) {
                    first_ = pre_;
                    second_ = root;
                } else {
                    second_ = root;
                    return;
                }
            }
        }

        pre_ = root;

        if (root->right) {
            dfs(root->right);
        }
    }

    void recoverTree(TreeNode *root) {
        pre_ = nullptr;
        first_ = nullptr;
        second_ = nullptr;
        dfs(root);

        swap(first_->val, second_->val);
    }

private:
    TreeNode *pre_;
    TreeNode *first_;
    TreeNode *second_;
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
