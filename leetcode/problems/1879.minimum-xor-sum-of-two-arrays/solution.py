from typing import List


class Solution:
    def minimumXORSum(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        f = [[0x3f3f3f3f for i in range(1 << n)] for i in range(n + 1)]
        f[0][0] = 0
        for i in range(n):
            for S in range(1 << n):
                cnt = 0

                for j in range(n):
                    if (S >> j) & 1:
                        cnt += 1

                if cnt == i:
                    for j in range(n):
                        if ((S >> j) & 1) == 0:
                            SS = S | (1 << j)
                            f[i + 1][SS] = min(f[i + 1][SS],
                                               f[i][S] + (nums1[i] ^ nums2[j]))

        return min(f[n])
