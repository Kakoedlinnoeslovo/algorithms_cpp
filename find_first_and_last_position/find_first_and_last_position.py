class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if (len(nums) == 0):
            return [-1, -1]

        if len(nums) == 1:
            if (nums[0] == target):
                return [0, 0]
            else:
                return [-1,-1]

        l, r = 0, len(nums) - 1
        while l <= r:
            m = int((l+r)/2)

            if target == nums[m]:
                toleft = m
                toright = m
                while toleft - 1 >=l and target == nums[toleft - 1]:
                    toleft -=1
                while toright + 1 <= r and target == nums[toright + 1] :
                    toright +=1
                return [toleft, toright]

            if target <= nums[m]:
                r = m - 1
            else:
                l = m + 1

        return [-1, -1]


sol = Solution()
print(sol.searchRange([5,6,6,7], 6))
