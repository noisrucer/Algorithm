'''
Follow up:
1) What if the given array is already sorted? How would you optimize your algorithm?
2) What if nums1's size is small compared to nums2's size? Which algorithm is better?
3) What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
'''


'''Method1 - Not Sorted
TC: O(n)
SC: O(n)
'''
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        freq = defaultdict(int)
        for e in nums1:
            freq[e] += 1
        for e in nums2:
            if freq[e] > 0:
                res.append(e)
                freq[e] -= 1
        return res
    

'''Method2 - Sorted
TC: O(n) (assumming it's already sorted)
SC: O(1)
'''
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1, nums2 = sorted(nums1), sorted(nums2)
        i, j = 0, 0
        n, m = len(nums1), len(nums2)
        res = []

        while i < n and j < m:
            if nums1[i] == nums2[j]:
                res.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1

        return res
            