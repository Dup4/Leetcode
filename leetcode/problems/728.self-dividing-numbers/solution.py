from typing import List


class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        def check(x: int) -> bool:
            y = x
            while x > 0:
                t = x % 10
                if t == 0 or y % t != 0:
                    return False
                x /= 10
            return True
        return list(filter(check, range(left, right + 1)))
