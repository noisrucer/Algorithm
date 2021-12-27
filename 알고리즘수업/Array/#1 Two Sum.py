'''
1) 문제정의: A[1] A[2] ... A[n]이 주어졌을때, A[i] + A[j] = target(i<j)를 만족하는 [i, j]를 구하여라.
2) 알고리즘: Array
3) 자료구조: Dictionary
4) 해결전략: 
   - A[i] + A[j] = target ... (1)
   - A[i] = target - A[j] 로 표현할수 있음 ... (2)
   - (2)를 풀어서 해석하면, i < j이기 때문에, 현재 index j를 기준으로 list의 왼쪽에(nums[ :j]) target - A[j] 가 존재한다면, 조건을 만족하는 pair를 찾음
   - 문제에서 exactly one solution 이라고 했기 때문에 찾는 즉시 [i, j]를 return 해줌

<TIPS>
1. (value, index) pair를 저장할때는 주로 dictionary를 쓴다.
2. 1) 문제정의 단계와 같이, "일반화"를 하면 더 직관적으로 핵심을 바라볼수 있는 가능성이 높아짐
3. 항상 "코드를 적기전에" 위와 같은 일련의 사고과정을 거치도록 연습하면, 나중에는 일일이 적지 않고도 머릿속으로 가능함 (하지만 어려운 문제일수록 해결전략 단계는 종이로 적음)
'''

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        indices = dict() #(value, index) pair를 저장 / indices[A[i]] = i 
        
        for j, val in enumerate(nums): # val: A[j]
            if (target - val) in indices.keys(): # A[i] = target - A[j]가 존재한다면 성공 
                return [indices[target - val], j] # i == indices[A[i]] = indices[target - A[j]]
            else: # (value, index)
                indices[val] = j # indices[A[i]] = i
        
        return 0
    
    
    
        