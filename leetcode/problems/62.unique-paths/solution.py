class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        f = [[0 for i in range(n + 1)] for j in range(m + 1)]
        f[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i - 1 >= 0:
                    f[i][j] += f[i - 1][j]
                if j - 1 >= 0:
                    f[i][j] += f[i][j - 1]
        return f[m - 1][n - 1]
