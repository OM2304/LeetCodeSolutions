class Solution:
    def search(self, nums: list[int], target: int) -> bool:
        n = len(nums)
        l = 0
        h = n-1

        while l<=h:
            mid = l + (h-l)//2
            if nums[mid]==target:
                return True

            if nums[mid]==nums[h] and nums[mid]==nums[l]:
                l = l+1
                h = h-1
                continue
            
            if nums[l]<=nums[mid]:
                if nums[l]<=target<nums[mid]:
                    h = mid-1
                else:
                    l = mid+1
            else:
                if nums[mid]<target<=nums[h]:
                    l = mid+1
                else:
                    h = mid-1
        return False

        