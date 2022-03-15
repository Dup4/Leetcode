from itertools import permutations


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        arr = range(1, n + 1)
        res = list(permutations(arr))[k - 1]
        return "".join(map(lambda x: str(x), res))
