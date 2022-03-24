from typing import List


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nums.append(n + 1)
        res = []
        for i in range(n):
            x = abs(nums[i])
            if nums[x] < 0:
                res.append(x)
            else:
                nums[x] *= -1

        return res
