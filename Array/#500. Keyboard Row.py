'''
TC: O(n)
SC: O(1)
'''
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        res = []
        key_line = [set("qwertyuiop"), set("asdfghjkl"), set("zxcvbnm")]

        for word in words:
            for line in key_line:
                if set(word.lower()).issubset(line):
                    res.append(word)
                    break

        return res
    
'''
TC: O(n)
SC: O(1)
''' 
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        res = []
        key_line = dict()
        for e in "qwertyuiop":
            key_line[e] = 1
        for e in "asdfghjkl":
            key_line[e] = 2
        for e in "zxcvbnm":
            key_line[e] = 3

        for word in words:
            if len(set(map(lambda x: key_line[x.lower()], word))) == 1:
                res.append(word)

        return res