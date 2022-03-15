# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import List, Optional


class Solution:
    def __init__(self) -> None:
        self.res = []

    def dfs(self, rt: TreeNode) -> None:
        if not rt:
            return

        self.res.append(rt.val)
        self.dfs(rt.left)
        self.dfs(rt.right)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.dfs(root)
        return self.res
