'''
1) 문제정의: A[1] A[2] ... A[n]이 주어졌을때, maximum subarray를 구하여라.
2) 알고리즘: Array - Kadane's Algorithm
3) 자료구조: None
4) 해결전략: 
   - A[i] + A[i+1] + ... + A[j] + A[j+1] < A[j+1]이면 cur_max = A[j+1]
     ㄴ무슨 뜻인지 고민해보기: kadane's algorithm의 핵심
   - cur_max가 업데이트 될때마다 glob_max = max(glob_max, cur_max)

<TIPS>
'''

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cur_max = glob_max = nums[0]
        
        for val in nums[1:]:
            cur_max = max(cur_max + val, val)
            glob_max = max(glob_max, cur_max)
        
        return glob_max
        