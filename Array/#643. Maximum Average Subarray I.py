class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n = len(nums)
        running_sum = 0
        max_avg = -inf
        for i in range(n):
            running_sum += nums[i]
            if i >= k - 1:
                if i > k - 1:
                    running_sum -= nums[i - k]
                max_avg = max(max_avg, running_sum / k)

        return max_avg
