#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap; // Map to store the number and its index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            // Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            // Store the current number and its index
            numMap[nums[i]] = i;
        }
        return {}; // Return an empty vector if no solution is found
    }
};
