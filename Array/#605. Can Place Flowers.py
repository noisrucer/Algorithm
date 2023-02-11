''' Greedy
'''
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        cnt = 0
        for i in range(len(flowerbed)):
            if flowerbed[i] == 0:
                empty_left = (i == 0) or (flowerbed[i - 1] == 0)
                empty_right = (i == len(flowerbed) - 1) or (flowerbed[i + 1] == 0)
                if empty_left and empty_right:
                    cnt += 1
                    flowerbed[i] = 1
                    if cnt >= n:
                        return True

        return cnt >= n
    
    
    
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        flowerbed.append(1)
        length = len(flowerbed)
        start = 0
        res = 0
        while start < length:
            while start < length and flowerbed[start] == 1:
                start += 1
            end = start + 1
            while end < length and flowerbed[end] == 0:
                end += 1
            zero_len = end - start
            if start == 0 and end == length - 1:
                res += (zero_len + 1) // 2
            elif start == 0 or end == length - 1:
                res += zero_len // 2
            else:
                res += (zero_len - 1) // 2

            start = end + 1
        return res >= n
        
        