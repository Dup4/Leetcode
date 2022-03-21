from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        ld = {}
        cd = {}
        for i, l in enumerate(matrix):
            for j, c in enumerate(l):
                if c == 0:
                    ld[i] = True
                    cd[j] = True

        for i, l in enumerate(matrix):
            for j, c in enumerate(l):
                if (i in ld.keys() and ld[i]) or (j in cd.keys()) and cd[j]:
                    matrix[i][j] = 0
