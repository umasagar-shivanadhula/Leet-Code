class Solution:
    def fourSum(self, nums, target):
        nums.sort()  # Sort the array to make it easier to avoid duplicates
        result = []
        n = len(nums)
        
        # Iterate through the array for the first element
        for i in range(n - 3):
            if i > 0 and nums[i] == nums[i - 1]:  # Skip duplicates for i
                continue
                
            # Iterate for the second element
            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:  # Skip duplicates for j
                    continue
                
                left, right = j + 1, n - 1  # Two-pointer approach for the remaining two numbers
                
                while left < right:
                    total = nums[i] + nums[j] + nums[left] + nums[right]
                    
                    if total == target:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
                        
                        # Skip duplicates for the third and fourth elements
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        
                        left += 1
                        right -= 1
                    elif total < target:
                        left += 1
                    else:
                        right -= 1
        
        return result


# Example usage
nums = [1, 0, -1, 0, -2, 2]
target = 0
solution = Solution()
result = solution.fourSum(nums, target)

# Print the result
for quad in result:
    print(quad)
