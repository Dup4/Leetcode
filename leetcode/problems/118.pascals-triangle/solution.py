from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1]]
        pre = res[0]
        for _ in range(numRows - 1):
            cur_res = [1]

            for i in range(len(pre) - 1):
                cur_res.append(pre[i] + pre[i + 1])

            cur_res.append(1)
            res.append(cur_res)
            pre = cur_res
        return res
