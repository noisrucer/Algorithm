class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        '''
        Total # candies: n
        
        # pick = n // 2
        # unique candies = len(set(candyType))

        if # unique >= n // 2:
            return n // 2
        if # unique < n // 2:
            return # unique
        '''

        return min(len(candyType) // 2, len(set(candyType)))
