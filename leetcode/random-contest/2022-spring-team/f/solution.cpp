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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#ifdef LOCAL

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif

class Solution {
public:
    int res, maxDep;
    int depSum[100000 + 10];

    void calc(TreeNode *rt, int dep) {
        if (rt == nullptr) {
            return;
        }
        maxDep = max(maxDep, dep);
        depSum[dep] += rt->val;
        calc(rt->left, dep + 1);
        calc(rt->right, dep + 1);
    }

    void gao(TreeNode *rt, int dep, int can) {
        if (rt == nullptr) {
            return;
        }
        if (rt->left != nullptr && rt->right == nullptr) {
            can = 1;
        }
        if (rt->right != nullptr && rt->left == nullptr) {
            can = 1;
        }
        if (can) {
            int sonSum = 0;
            if (rt->left != nullptr) {
                sonSum += rt->left->val;
            }
            if (rt->right != nullptr) {
                sonSum += rt->right->val;
            }
            res = max(res, depSum[dep] - (rt->val) + sonSum);
        }

        gao(rt->left, dep + 1, can);
        gao(rt->right, dep + 1, can);
    }

    int getMaxLayerSum(TreeNode *root) {
        memset(depSum, 0, sizeof depSum);
        maxDep = 0;
        res = -0x3f3f3f3f;
        calc(root, 1);
        for (int i = 1; i <= maxDep; ++i) {
            res = max(res, depSum[i]);
        }
        gao(root, 1, 0);
        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
