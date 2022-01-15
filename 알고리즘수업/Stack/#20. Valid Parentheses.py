'''
1) 문제정의: 주어진 문자열(괄호)가 valid한 괄호들인지 확인
2) 알고리즘: Stack
3) 자료구조: Stack
4) 해결전략: 
   - ], }, )가 있으면 stack 바로 직전의 괄호는 무조건 각각 [, {, ( 이여야 함 -> 왜? 
   - [, {, (은 stack push, ], }, )은 바로 직전 괄호를 확인되고 매칭되면 pop, 매칭안되면 return false

<TIPS>
'''

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