from typing import List


class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n = len(nums)
        max_res = 0
        num = 0
        for S in range(1 << n):
            cur = 0
            for i in range(n):
                if (S >> i) & 1:
                    cur |= nums[i]

            if cur > max_res:
                max_res = cur
                num = 1
            elif cur == max_res:
                num += 1

        return num
