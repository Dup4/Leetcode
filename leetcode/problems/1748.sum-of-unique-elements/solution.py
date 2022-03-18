from typing import Counter, List


class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        m = Counter(nums)
        return sum(filter(lambda x: m[x] == 1, m.keys()))
