from typing import List


class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        return bisect_right(range(1, sum(candies) + 1), -1, key=lambda x: -(sum(i // x for i in candies) >= k))
