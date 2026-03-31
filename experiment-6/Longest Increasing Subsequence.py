class Solution(object):
    def lengthOfLIS(self, nums):
        arr=[1]*len(nums)
        for i in range(len(nums)):
            for j in range(i):
                if nums[j]<nums[i]:
                    arr[i]=max(arr[i],arr[j]+1)
        return max(arr)
