from bisect import bisect_left
from typing import List


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        return nums[bisect_left(range(n), 0, 0, n, key=lambda ix: -1 if nums[ix] == nums[ix ^ 1] else 0)]
