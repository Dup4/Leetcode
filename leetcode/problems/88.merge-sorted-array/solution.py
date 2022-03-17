from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        i = n + m - 1
        j = m - 1
        k = n - 1
        while i >= 0:
            if j < 0:
                nums1[i] = nums2[k]
                k -= 1
            elif k < 0:
                nums1[i] = nums1[j]
                j -= 1
            else:
                if nums1[j] >= nums2[k]:
                    nums1[i] = nums1[j]
                    j -= 1
                else:
                    nums1[i] = nums2[k]
                    k -= 1
            i -= 1
