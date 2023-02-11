''' Method 0 - BFS Greedy
'''
class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        res, max_reach = 0, 0
        curr_max = 0
        for i in range(n - 1):
            max_reach = max(max_reach, i + nums[i])
            if i == curr_max:
                res += 1
                curr_max = max_reach

        return res
        


''' Method 1 - Topdown
f(i): # min jumps to reach n - 1 from i

Base case
if i >= n - 1:
    return 0

General case
f(i) = 1 + min({f(i + k), 0 <= k <= nums[i]})
        
'''
class Solution:
    def jump(self, nums: List[int]) -> int:
        self.n = len(nums)
        self.dp = [-1 for _ in range(self.n)]
        return self.topdown(nums, 0)


    def topdown(self, nums, i):
        if i >= self.n - 1:
            return 0

        if self.dp[i] != -1:
            return self.dp[i]

        curr_min = math.inf
        for step in range(1, nums[i] + 1):
            curr_min = min(curr_min, 1 + self.topdown(nums, i + step))

        self.dp[i] = curr_min
        return self.dp[i]

        
''' Method 2 - Bottom up
'''
class Solution:
    def jump(self, nums: List[int]) -> int:
        # Bottom-up solution
        n = len(nums)
        dp = [math.inf for _ in range(n)]
        dp[0] = 0

        for i in range(n - 1):
            if dp[i] == math.inf:
                break
            for step in range(1, nums[i] + 1):
                if i + step >= n:
                    break
                dp[i + step] = min(dp[i + step], 1 + dp[i])


        return dp[n - 1]