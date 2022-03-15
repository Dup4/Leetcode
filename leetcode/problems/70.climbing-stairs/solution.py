class Solution:
    f = {}

    def dfs(self, n: int) -> int:
        if n < 0:
            return 0
        if n == 0:
            return 1

        if n not in self.f.keys():
            self.f[n] = self.dfs(n - 1) + self.dfs(n - 2)

        return self.f[n]

    def climbStairs(self, n: int) -> int:
        return self.dfs(n)
