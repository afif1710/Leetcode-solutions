class Solution(object):
    def longestConsecutive(self, nums):
        st = set(nums)
        l = 0
        for i in nums:
            if(i-1) not in st:
                len = 0
                while (i+len) in st:
                    len += 1
                l = max(l, len)
        return l