from bisect import bisect, bisect_left, bisect_right
from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = bisect_left(nums, target)
        r = bisect_right(nums, target)
        if l == len(nums) or nums[l] != target:
            return [-1, -1]
        return [l, r - 1]


if __name__ == "__main__":
    s = Solution()
    ans = s.searchRange([5, 7, 7, 8, 8, 10], 8)
    print(ans)

    ans = s.searchRange([1, 2, 3, 4, 5], 10)
    print(ans)
