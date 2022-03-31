from typing import List


class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        def f(s):
            if "+" in s:
                return 1
            return -1
        return sum(map(f, operations))
