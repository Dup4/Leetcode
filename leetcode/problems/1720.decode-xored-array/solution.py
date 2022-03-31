from typing import List


class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        res = [first]
        for x in encoded:
            res.append(x ^ res[-1])
        return res
