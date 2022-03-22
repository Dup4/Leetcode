# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

from bisect import bisect_left


class Solution:
    def guessNumber(self, n: int) -> int:
        return bisect_left(range(n + 1), 0, 1, key=lambda x: -guess(x))
