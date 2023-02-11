'''
f(i, j) = list of unique BSTs from i to j: [node, node, ...]

Base case
f(i > j) = None
f(i==j) = [TreeNode(nums[i])]

General case
f(i, j) = For k in [i, j],
TreeNode(nums[k]).left = each in f(i, k - 1)
TreeNode(nums[k]).right = each in f(k + 1, j)
'''
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        self.dp = [[-1 for _ in range(n + 1)] for _ in range(n + 1)]
        return self.topdown(1, n)

    def topdown(self, i, j):
        if i > j:
            return [None]
        if i == j:
            return [TreeNode(i)]
        if self.dp[i][j] != -1:
            return self.dp[i][j]

        res = []
        for k in range(i, j + 1):
            left_list = self.topdown(i, k - 1)
            right_list = self.topdown(k + 1, j)
            for l in left_list:
                for r in right_list:
                    node = TreeNode(k, l, r)
                    res.append(node)
        self.dp[i][j] = res

        return res
