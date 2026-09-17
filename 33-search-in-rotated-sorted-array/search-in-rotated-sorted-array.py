class Solution(object):
    def search(self, nums, target):
        s = len(nums)
        l = 0
        h = s-1
        while l<=h:
            mid = l +(h-l)//2
            if nums[mid]==target:
                return mid
            
            if nums[mid]>nums[s-1]:
                if target>nums[s-1] and target<nums[mid]:
                    h = mid-1
                else:
                    l = mid+1
            else:
                if target<=nums[s-1] and target>nums[mid]:
                    l = mid+1
                else:
                    h = mid-1
        return -1
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        