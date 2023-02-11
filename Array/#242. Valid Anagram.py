'''
TC: O(n)
SC: O(n)
'''

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq = defaultdict(int)
        if len(s) != len(t):
            return False
        
        for i in range(len(s)):
            freq[s[i]] += 1
            freq[t[i]] -= 1

        for v in freq.values():
            if v != 0:
                return False

        return True
            