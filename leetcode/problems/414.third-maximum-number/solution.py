from typing import List


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        LOW = -0x3f3f3f3f3f3f3f3f
        max = [LOW for i in range(3)]
        for a in nums:
            cur = a
            for i in range(3):
                if cur > max[i]:
                    cur, max[i] = max[i], cur
                elif cur == max[i]:
                    break

        if max[2] == LOW:
            return max[0]

        return max[2]
