from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        for S in range(1 << n):
            cur_res = []
            for i in range(n):
                if (S >> i) & 1:
                    cur_res.append(nums[i])
            res.append(cur_res)
        uni = {}
        r_res = []
        for item in res:
            item.sort()
            key = str(item)
            if key not in uni.keys():
                uni[key] = 1
                r_res.append(item)
        return r_res
