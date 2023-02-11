class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ""
        i = 0
        while True:
            if i >= len(strs[0]):
                return res
            c = strs[0][i]
            for word in strs:
                if i >= len(word) or word[i] != c :
                    return res
            res += c
            i += 1
        return res