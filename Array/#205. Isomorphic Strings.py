class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        seen_s = dict()
        seen_t = dict()
        for i in range(len(s)):
            if s[i] in seen_s and seen_s[s[i]] != t[i]:
                return False
            if t[i] in seen_t and seen_t[t[i]] != s[i]:
                return False
            
            seen_s[s[i]] = t[i]
            seen_t[t[i]] = s[i]
        return True