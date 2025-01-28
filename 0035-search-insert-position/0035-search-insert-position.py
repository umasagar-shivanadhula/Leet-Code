class Solution:
    def searchInsert(self, nums, target):
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        return left  # If target is not found, return the index where it would be inserted

# Example usage:
nums = [1, 3, 5, 6]
target = 5
sol = Solution()
print(sol.searchInsert(nums, target))  # Output: 2
