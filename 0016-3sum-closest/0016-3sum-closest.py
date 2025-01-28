class Solution:
    def threeSumClosest(self, nums, target):
        # Sort the array
        nums.sort()
        
        closest_sum = float('inf')  # Initialize the closest sum as infinity
        
        for i in range(len(nums) - 2):  # We need at least three numbers for a triplet
            # Skip duplicates to avoid counting the same triplet more than once
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            left, right = i + 1, len(nums) - 1  # Initialize two pointers
            
            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]
                
                # Check if the current sum is closer to the target
                if abs(current_sum - target) < abs(closest_sum - target):
                    closest_sum = current_sum
                
                # Move the pointers based on the current sum
                if current_sum < target:
                    left += 1
                elif current_sum > target:
                    right -= 1
                else:
                    # If the current sum is equal to the target, return the sum
                    return current_sum
        
        return closest_sum  # Return the closest sum found
