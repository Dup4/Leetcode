class Solution:
    def reverse(self, x: int) -> int:
        l = -(1 << 31)
        r = (1 << 31) - 1
        f = 0
        if x < 0:
            f = 1
            x = -x

        x = int(str(x)[::-1])
        x *= -1 if f else 1
        if x < l or x > r:
            return 0
        return x
