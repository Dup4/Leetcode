# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        res = []

        def dfs(rt):
            if not rt:
                res.append(str(1001))
                return
            res.append(str(rt.val))
            dfs(rt.left)
            dfs(rt.right)

        dfs(root)

        return ",".join(res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        data = data.split(",")
        ix = [-1]

        def dfs():
            ix[0] += 1
            if ix[0] >= len(data):
                return None

            cur = int(data[ix[0]])
            if cur == 1001:
                return None

            t = TreeNode()
            t.val = cur
            t.left = dfs()
            t.right = dfs()
            return t

        return dfs()


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
