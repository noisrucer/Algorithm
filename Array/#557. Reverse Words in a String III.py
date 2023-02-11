class Solution:
    def reverseWords(self, s: str) -> str:
        last_space_idx = -1
        s = list(s)
        n = len(s)

        for i in range(n + 1): # n + 1 -> dummy index!!!!!!!!!!!!!!
            if i == n or s[i] == ' ':
                l, r = last_space_idx + 1, i - 1
                s[l: r + 1] = s[l: r + 1][::-1]
                last_space_idx = i

        return ''.join(s)
        
        
        
class Solution:
    def reverseWords(self, s: str) -> str:
        s = list(s.strip())
        s.append(' ')
        n = len(s)
        start = 0
        while start < n:
            end = start + 1
            while end < n and s[end] != ' ':
                end += 1
            s[start: end] = s[start: end][::-1]
            
            start = end
            while start < n and s[start] == ' ':
                start += 1

        return ''.join(s[:-1])