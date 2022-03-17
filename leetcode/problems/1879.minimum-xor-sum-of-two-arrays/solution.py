from typing import List


class Solution:
    def minimumXORSum(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        f = [0x3f3f3f3f for i in range(1 << n)]
        f[0] = 0
        for S in range(1, 1 << n):
            cnt = bin(S).count("1")

            for i in range(n):
                if (S >> i) & 1:
                    f[S] = min(f[S], f[S ^ (1 << i)] +
                               (nums1[cnt - 1] ^ nums2[i]))

        return f[-1]
