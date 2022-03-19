from typing import Counter, List


class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        a = Counter(nums)
        n = len(nums)
        for k in a:
            if a[k] & 1:
                return False
        return (n // 2) >= len(a.keys())
