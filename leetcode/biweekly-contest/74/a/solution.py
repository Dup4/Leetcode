from typing import Counter, List


class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        a = Counter(nums)
        return all((v & 1 == 0) for v in a.values()) and (len(nums) // 2) >= len(a.keys())
