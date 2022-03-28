# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, rt: TreeNode) -> None:
        if not rt:
            return

        rt.left, rt.right = rt.right, rt.left
        self.dfs(rt.left)
        self.dfs(rt.right)

    def invertTree(self, root: TreeNode) -> TreeNode:
        self.dfs(root)
        return root
