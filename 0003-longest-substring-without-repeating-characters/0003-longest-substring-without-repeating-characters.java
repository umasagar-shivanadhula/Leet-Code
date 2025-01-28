import java.util.HashSet;

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> charSet = new HashSet<>();  // Set to store unique characters in the current window
        int left = 0;  // Left pointer of the window
        int maxLength = 0;  // To track the length of the longest substring
        
        for (int right = 0; right < s.length(); right++) {
            // If the character is already in the set, slide the left pointer
            while (charSet.contains(s.charAt(right))) {
                charSet.remove(s.charAt(left));  // Remove the character at the left pointer
                left++;  // Move the left pointer to the right
            }
            
            charSet.add(s.charAt(right));  // Add the current character to the set
            maxLength = Math.max(maxLength, right - left + 1);  // Update the max length
        }
        
        return maxLength;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        
        // Test cases
        System.out.println(sol.lengthOfLongestSubstring("abcabcbb"));  // Output: 3 (substring "abc")
        System.out.println(sol.lengthOfLongestSubstring("bbbbb"));     // Output: 1 (substring "b")
        System.out.println(sol.lengthOfLongestSubstring("pwwkew"));    // Output: 3 (substring "wke")
    }
}
