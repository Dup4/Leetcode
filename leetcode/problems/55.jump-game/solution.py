from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        res = 0
        for i, a in enumerate(nums):
            if res < i:
                return False

            st = max(i, res)
            res = max(res, i + a)

        return True
