# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional


class Solution:
    def __init__(self):
        self.max_dep = 0
        self.sum = 0

    def dfs(self, rt, d):
        if not rt:
            return
        d += 1

        if d > self.max_dep:
            self.sum = rt.val
            self.max_dep = d
        elif d == self.max_dep:
            self.sum += rt.val

        self.dfs(rt.left, d)
        self.dfs(rt.right, d)

    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        self.dfs(root, 0)
        return self.sum
