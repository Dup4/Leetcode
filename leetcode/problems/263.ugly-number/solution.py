class Solution:
    def isUgly(self, x: int) -> bool:
        if x <= 0:
            return False

        def gao(x, y):
            while x % y == 0:
                x /= y
            return x

        x = gao(x, 2)
        x = gao(x, 3)
        x = gao(x, 5)

        return x == 1
