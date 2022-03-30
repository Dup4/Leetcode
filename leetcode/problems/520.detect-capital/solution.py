class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return word.isupper() or word.islower() or all(word[i].isupper() ^ (i & 1) for i in range(len(word)))
