# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional


class Solution:
    def __init__(self):
        self.res = False

    def dfs(self, rt: TreeNode, sum: int) -> None:
        if not rt:
            return

        sum += rt.val

        if not rt.left and not rt.right:
            if sum == self.target:
                self.res = True
            return

        self.dfs(rt.left, sum)
        self.dfs(rt.right, sum)

    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        self.target = targetSum
        self.dfs(root, 0)
        return self.res
