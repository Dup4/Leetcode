from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        m = {}
        for s in strs:
            k = "".join(sorted(s))
            try:
                m[k].append(s)
            except KeyError:
                m[k] = [s]

        return [m[k] for k in m]


if __name__ == "__main__":
    s = Solution()

    ans = s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])

    print(ans)
