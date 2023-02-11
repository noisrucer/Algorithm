'''
TC: O(N * N!)
SC: O(N!) for call stacks
'''
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        self.nums = nums
        self.gen_perm(nums, [])
        return self.res

    def gen_perm(self, design_space, temp):
        if not design_space:
            self.res.append(temp[:])
            return None

        for i in range(len(design_space)):
            temp.append(design_space[i])
            self.gen_perm(design_space[:i] + design_space[i+1:], temp)
            temp.pop()
        
