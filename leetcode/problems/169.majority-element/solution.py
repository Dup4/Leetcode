from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res = -1
        cnt = 0
        for a in nums:
            if cnt == 0:
                res = a
                cnt = 1
            elif a != res:
                cnt -= 1
            else:
                cnt += 1
        return res
