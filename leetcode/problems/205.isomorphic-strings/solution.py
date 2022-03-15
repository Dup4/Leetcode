class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        sd = {}
        st = {}
        for i in range(len(s)):
            try:
                if sd[s[i]] != t[i]:
                    return False
            except KeyError:
                sd[s[i]] = t[i]

            try:
                if st[t[i]] != s[i]:
                    return False
            except KeyError:
                st[t[i]] = s[i]

        return True
