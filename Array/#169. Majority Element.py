'''
Method1
TC: O(n)
SC: O(1)

[Description]
freq(maj el) >= floor(n / 2) + 1
freq(rest of all) <= n - floor(n / 2) - 1
freq(maj el) - freq(rest of all) = -n + 2 * floor(n / 2) + 2
if n is even -> -n + n + 2 = 2
if n is odd -> -n + (n - 1) + 2 = 1
'''

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnt = 1
        target = nums[0]

        for e in nums[1:]:
            if cnt == 0:
                cnt = 1
                target = e
                continue
            if target == e:
                cnt += 1
            else:
                cnt -= 1

        return target

'''Method2
TC: O(n)
SC: O(n)
'''
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        running_freq = 1
        target = nums[0]

        for e in nums[1:]:
            if e == target:
                if running_freq == 0:
                    target = e
                running_freq += self.sign(running_freq)
            else:
                if running_freq == 0:
                    target = e
                running_freq += (-1 * self.sign(running_freq))

        return target

    def sign(self, i):
        if i > 0:
            return 1
        else:
            return -1