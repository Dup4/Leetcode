# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional


class Solution:
    res = 0

    def dfs(self, rt: TreeNode, d: int) -> None:
        if not rt:
            return

        cur_d = d + 1
        self.res = max(self.res, cur_d)
        self.dfs(rt.left, cur_d)
        self.dfs(rt.right, cur_d)

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        self.dfs(root, 0)
        return self.res
