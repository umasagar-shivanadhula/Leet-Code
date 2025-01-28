#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty()) return result;

        int word_len = words[0].size();
        int total_len = word_len * words.size();
        unordered_map<string, int> word_count;
        
        // Count the frequency of each word in the words array
        for (const string& word : words) {
            word_count[word]++;
        }
        
        // Slide through the string
        for (int i = 0; i < word_len; i++) {  // We need to check 0 to word_len-1 positions for different offsets
            int left = i;
            int right = i;
            unordered_map<string, int> current_count;

            while (right + word_len <= s.size()) {
                // Get the current word from the substring
                string word = s.substr(right, word_len);
                right += word_len;

                // If the word is in the list, we process it
                if (word_count.find(word) != word_count.end()) {
                    current_count[word]++;

                    // If there are more occurrences of the word than in word_count, move left pointer
                    while (current_count[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        current_count[left_word]--;
                        left += word_len;
                    }

                    // If we have a valid window, add the left index to the result
                    if (right - left == total_len) {
                        result.push_back(left);
                    }
                } else {
                    // Reset the current window if the word is not in the list
                    current_count.clear();
                    left = right;
                }
            }
        }
        
        return result;
    }
};
