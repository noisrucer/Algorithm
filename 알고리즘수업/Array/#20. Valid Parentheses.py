class Solution:
    def isValid(self, s: str) -> bool:
        mapping = {"}" : "{",
                   "]" : "[",
                   ")" : "("}
        stk = []
        # push(x): stk.append(x)
        # pop(): stk.pop()
        # top(): stk[-1]
        # isEmpty(): len(stk) == 0
        
        for c in s:
            if c=="(" or c=="[" or c=="{":
                stk.append(c)
            else:
                if len(stk) == 0: # empty
                    return False
                if stk[-1] is not mapping[c]: # mismatch
                    return False
                
                stk.pop()
                
        return len(stk) == 0