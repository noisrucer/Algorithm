class Solution:
    def longestPalindrome(self, s: str) -> int:
        freq = dict()
        num_even = 0
        
        for e in s:
            if e not in freq:
                freq[e] = 1
            else:
                freq[e] += 1
                if freq[e] == 2:
                    num_even += 1
                    freq.pop(e)

        return num_even * 2 + (len(freq) != 0)

        