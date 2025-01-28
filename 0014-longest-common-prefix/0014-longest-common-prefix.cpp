#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // Return empty if the input is empty

        string prefix = strs[0]; // Assume the first string as the prefix
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1); // Reduce the prefix
                if (prefix.empty()) return ""; // Return empty if no common prefix exists
            }
        }
        return prefix; // Return the longest common prefix
    }
};
