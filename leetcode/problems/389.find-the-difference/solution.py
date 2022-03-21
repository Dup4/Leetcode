from collections import Counter


class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        sd = Counter(s)
        st = Counter(t)
        for k, v in st.items():
            try:
                if v == sd[k] + 1:
                    return k
            except KeyError:
                return k
