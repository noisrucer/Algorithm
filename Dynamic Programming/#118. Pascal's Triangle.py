'''
Method 1 - lambda function
TC: O(n^2)
Extra SC: O(n) for prev, curr

[Description]
1 4 6 4 1
  1 4 6 4 1 
-------------
1 5 10 10 5 1
'''
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascals = []
        pascals.append([1])
        for i in range(1, numRows):
            prev = pascals[i - 1]
            curr = [1] + list(map(lambda x, y: x + y, prev[:i - 1], prev[1:])) + [1]
            pascals.append(curr)
        return pascals
        
        
'''
Method 2 - For loop
Same as above

[Description]
level = i
level_len = i + 1
For j in [1, i - 1], pascals[i][j] = pascals[i - 1][j - 1] + pascals[i - 1][j]
'''
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascals = []
        pascals.append([1])
        for i in range(1, numRows):
            cur = [1]
            for j in range(1, i):
                cur.append(pascals[i - 1][j - 1] + pascals[i - 1][j])
            cur.append(1)
            pascals.append(cur)
        return pascals
    
    
'''
Method 3 - List Comprehension
Same as above

[Description]
level = i
level_len = i + 1
For j in [1, i - 1], pascals[i][j] = pascals[i - 1][j - 1] + pascals[i - 1][j]
'''
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascals = []
        pascals.append([1])
        for i in range(1, numRows):
            cur = [1]
            cur += [pascals[i - 1][prev_j - 1] + pascals[i - 1][prev_j] for prev_j in range(1, i)]
            cur += [1]
            pascals.append(cur)
        return pascals

