from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        l, r = 0, n - 1
        for i in range(n):
            pre = nums[i]
            while True:
                if nums[i] == 0:
                    while l < i and nums[l] == 0:
                        l += 1
                    nums[l], nums[i] = nums[i], nums[l]
                elif nums[i] == 2:
                    while r > i and nums[r] == 2:
                        r -= 1
                    nums[r], nums[i] = nums[i], nums[r]
                else:
                    break

                if nums[i] == pre:
                    break

                pre = nums[i]
