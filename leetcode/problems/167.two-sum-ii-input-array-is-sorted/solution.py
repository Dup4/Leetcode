from typing import List


class Solution:
    def twoSum(self, a: List[int], target: int) -> List[int]:
        n = len(a)
        k = n - 1
        for i in range(n):
            while k > 0 and a[i] + a[k] > target:
                k -= 1
            if a[i] + a[k] == target:
                if i > k:
                    i, k = k, i
                return [i + 1, k + 1]
