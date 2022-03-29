from typing import List


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        i = 0
        sum = 0
        res = -10000
        for j in range(len(nums)):
            sum += nums[j]
            while j - i + 1 > k:
                sum -= nums[i]
                i += 1
            if j - i + 1 == k:
                res = max(res, sum / k)
        return res
