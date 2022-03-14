# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional


class Solution:
    res = -1000

    def dfs(self, root: TreeNode) -> int:
        if not root:
            return 0

        left = self.dfs(root.left)
        right = self.dfs(root.right)
        val = root.val

        self.res = max(self.res, left + right + val,
                       left + val, right + val, val)
        return max(val, left + val, right + val)

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.res
