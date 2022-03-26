from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        pre = -1e5
        num = 0
        n = len(nums)
        ix = 0
        for i in range(n):
            cur = nums[i]
            if cur == pre and num >= 2:
                continue
            nums[ix] = cur
            ix += 1
            if cur == pre:
                num += 1
            else:
                pre = cur
                num = 1
