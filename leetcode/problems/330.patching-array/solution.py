from collections import Counter
from typing import List


class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        base = 0
        res = 0

        for i in nums:
            while base + 1 < i and base < n:
                base <<= 1
                base += 1
                res += 1
            base += i

        while base < n:
            base <<= 1
            base += 1
            res += 1

        return res
