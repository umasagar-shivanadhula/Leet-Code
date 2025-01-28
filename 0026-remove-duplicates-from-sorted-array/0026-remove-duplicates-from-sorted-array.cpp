#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int k = 1; // Pointer for the position of the next unique element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // Check if the current element is unique
                nums[k] = nums[i]; // Update the position with the unique element
                k++;
            }
        }
        return k; // Return the count of unique elements
    }
};
