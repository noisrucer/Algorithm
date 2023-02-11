class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        freq = defaultdict(int)
        val2idx = dict()
        max_freq = 1
        min_len = inf
        
        for i in range(len(nums)):
            if nums[i] not in val2idx:
                val2idx[nums[i]] = i

            freq[nums[i]] += 1
            if freq[nums[i]] > max_freq:
                max_freq = freq[nums[i]]
                min_len = i - val2idx[nums[i]] + 1
            elif freq[nums[i]] == max_freq:
                min_len = min(min_len, i - val2idx[nums[i]] + 1)

        return min_len



        