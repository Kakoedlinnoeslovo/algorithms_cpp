

class Solution:
    def search(self, nums, target):
        if len(nums) == 0:
            return -1

        if len(nums) == 1:
            if nums[0] == target:
                return 0
            else:
                return -1

        s, e = 0, len(nums) - 1
        while (s <= e):
            m = int((s + e)/2)
            if nums[m] == target:
                return m

            if nums[s] <= nums[m]:
                if nums[s]<=target<=nums[m]:
                    e = m - 1
                else:
                    s = m + 1
            else:
                if nums[m]<=target<=nums[e]:
                    e = m + 1
                else:
                    s = m - 1
        return - 1


sol = Solution()
print(sol.search([4,5,6,7,0,1,2], 0))