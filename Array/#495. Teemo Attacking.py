class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        res = 0
        start, end = timeSeries[0], timeSeries[0] + duration - 1

        for time in timeSeries:
            if end < time:
                res += (end - start + 1)
                start = time
            end = time + duration - 1

        res += (end - start + 1)
        return res