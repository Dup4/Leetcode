from functools import reduce
from typing import List


class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        xorSum = reduce(lambda x, y: x ^ y, nums)
        l = len(nums)
        return xorSum == 0 or (l & 1) == 0
