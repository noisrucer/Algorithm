class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        self.dp = dict()
        return self.dfs(expression)
        

    def dfs(self, exp):
        if exp in self.dp:
            return self.dp[exp]
        if exp.isdigit():
            return [int(exp)]
        res = []
        for i in range(len(exp)):
            if not exp[i].isdigit():
                left = self.dfs(exp[:i])
                right = self.dfs(exp[i+1:])
                for l in left:
                    for r in right:
                        res.append(self.cal(l, r, exp[i]))
        self.dp[exp] = res
        return self.dp[exp]
        

    def cal(self, x, y, op):
        if op == '+':
            return x + y
        elif op == '-':
            return x - y
        else:
            return x * y


        
