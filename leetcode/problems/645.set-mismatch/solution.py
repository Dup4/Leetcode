from typing import List


class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        a = [i for i in range(1, n + 1)]
        s = sum(a)
        y = list(set(s) - set(a))
        x = a + y - s
        return [x, y]
