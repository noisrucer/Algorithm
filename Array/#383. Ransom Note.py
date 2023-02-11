class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        freq = defaultdict(int)
        for e in magazine:
            freq[e] += 1
        for e in ransomNote:
            if freq[e] == 0:
                return False
            freq[e] -= 1

        return True