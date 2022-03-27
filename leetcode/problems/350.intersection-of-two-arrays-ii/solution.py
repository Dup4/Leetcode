from collections import Counter
from typing import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        a = Counter(nums1)
        b = Counter(nums2)
        res = []
        for k, v in a.items():
            if k in b.keys():
                res.extend([k] * min(v, b[k]))
        return res
