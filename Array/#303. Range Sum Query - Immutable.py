class NumArray:
    
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.prefix = nums[:]
        for i in range(1, len(nums)):
            self.prefix[i] += self.prefix[i - 1]


    def sumRange(self, left: int, right: int) -> int:
        res = self.prefix[right]
        res -= self.prefix[left - 1] if left > 0 else 0
        return res


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)