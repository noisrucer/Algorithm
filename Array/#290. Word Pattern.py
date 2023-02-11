class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = s.split()
        if len(pattern) != len(s):
            return False

        pattern2s, s_visit = dict(), set()
        for i in range(len(pattern)):
            if pattern[i] in pattern2s:
                if pattern2s[pattern[i]] != s[i]:
                    return False
            else:
                if s[i] in s_visit:
                    return False
            pattern2s[pattern[i]] = s[i]
            s_visit.add(s[i])
            
        return True

