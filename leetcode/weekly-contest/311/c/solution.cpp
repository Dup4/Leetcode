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
    TreeNode *t{nullptr};
    int dep{0};
};

class Solution {
public:
    TreeNode *reverseOddLevels(TreeNode *root) {
        queue<node> q;
        q.push(node{
                .t = root,
                .dep = 0,
        });

        auto vec = vector<vector<node>>(20, vector<node>{});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            vec[front.dep].push_back(front);
            if (front.t->left) {
                q.push(node{
                        .t = front.t->left,
                        .dep = front.dep + 1,
                });
            }

            if (front.t->right) {
                q.push(node{
                        .t = front.t->right,
                        .dep = front.dep + 1,
                });
            }
        }

        for (int i = 1; i < 20; i += 2) {
            int n = int(vec[i].size());
            for (int j = 0, k = n - 1; j < k; j++, k--) {
                swap(vec[i][j].t->val, vec[i][k].t->val);
            }
        }

        return root;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
