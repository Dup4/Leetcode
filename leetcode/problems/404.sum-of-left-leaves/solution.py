# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional


class Solution:
    def __init__(self):
        self.res = 0

    def dfs(self, root: Optional[TreeNode], is_left: bool) -> None:
        if not root:
            return

        son = 0
        if root.left:
            son += 1
            self.dfs(root.left, True)

        if root.right:
            son += 1
            self.dfs(root.right, False)

        if son == 0 and is_left:
            self.res += root.val

    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        self.dfs(root, False)
        return self.res
