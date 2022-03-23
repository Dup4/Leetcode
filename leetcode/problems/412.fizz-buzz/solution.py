from typing import List


class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        def run(x: int) -> str:
            s = ""

            if x % 3 == 0:
                s = s + "Fizz"
            if x % 5 == 0:
                s = s + "Buzz"

            if len(s) == 0:
                s = str(x)

            return s

        return list(map(run, range(1, n + 1)))
