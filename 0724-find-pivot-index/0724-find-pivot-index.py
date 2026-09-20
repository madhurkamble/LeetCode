class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        t = sum(nums)
        ls = 0
        for i in range(len(nums)):
            if ls == t - ls - nums[i]:
                return i
            ls += nums[i]
        return -1