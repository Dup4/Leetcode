class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n == 0:
            return 0

        f = [0 for i in range(n + 1)]
        f[1] = 1

        for i in range(1, n + 1):
            if (2 * i) <= n:
                f[2 * i] = f[i]
            if (2 * i + 1) <= n:
                f[2 * i + 1] = f[i] + f[i + 1]

        return max(f)
