class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.res = []
        self.dfs(nums, [])
        return self.res


    def dfs(self, dec_space, temp):
        if not dec_space:
            self.res.append(temp[:])
            return None

        for i in range(len(dec_space)):
            if i > 0 and dec_space[i] == dec_space[i - 1]:
                continue
            temp.append(dec_space[i])
            self.dfs(dec_space[:i] + dec_space[i + 1:], temp)
            temp.pop()
        