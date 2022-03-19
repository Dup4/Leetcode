# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, l: TreeNode, r: TreeNode) -> bool:
        if not l and not r:
            return True

        if not l or not r:
            return False

        if l.val != r.val:
            return False

        return self.dfs(l.left, r.left) and self.dfs(l.right, r.right)

    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        return self.dfs(p, q)
