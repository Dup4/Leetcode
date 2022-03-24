from typing import List


class NumArray:
    def __init__(self, nums: List[int]):
        self.sum = []
        self.sum.append(0)
        for a in nums:
            self.sum.append(self.sum[-1] + a)

    def sumRange(self, left: int, right: int) -> int:
        return self.sum[right + 1] - self.sum[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
