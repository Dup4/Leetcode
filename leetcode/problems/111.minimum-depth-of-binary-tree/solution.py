# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.res = 1000000

    def dfs(self, rt: TreeNode, d: int) -> None:
        if not rt.left and not rt.right:
            self.res = min(self.res, d)

        if rt.left:
            self.dfs(rt.left, d + 1)

        if rt.right:
            self.dfs(rt.right, d + 1)

    def minDepth(self, root: TreeNode) -> int:
        self.dfs(root, 1)
        return self.res
