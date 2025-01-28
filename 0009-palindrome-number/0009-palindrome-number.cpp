class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending with 0 (except 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed = 0; // To store the reversed half of the number
        int original = x;

        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // Check if the number is a palindrome
        // For even-length numbers, x should equal reversed
        // For odd-length numbers, ignore the middle digit using reversed/10
        return x == reversed || x == reversed / 10;
    }
};
