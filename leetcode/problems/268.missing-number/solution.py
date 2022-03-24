from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums = list(map(lambda x: x + 1, nums))
        nums.append(1)
        nums.append(1)
        n = len(nums)
        for i in range(n - 2):
            x = abs(nums[i])
            nums[x] *= -1

        for i in range(1, n):
            if nums[i] > 0:
                return i - 1
