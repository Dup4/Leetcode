import enum
from typing import List


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        m = {}
        for i, a in enumerate(nums):
            if a in m.keys():
                if (i - m[a]) <= k:
                    return True
            m[a] = i
        return False
