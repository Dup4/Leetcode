from bisect import bisect_left


class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False

        x = bisect_left(range(20), n, key=lambda x: 3 ** x)
        return 3 ** x == n
