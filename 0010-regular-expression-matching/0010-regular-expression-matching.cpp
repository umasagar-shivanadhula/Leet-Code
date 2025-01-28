class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] will be true if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Empty string and empty pattern match
        dp[0][0] = true;

        // Handle patterns like a*, a*b*, a*b*c* etc.
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2]; // Match zero occurrence of the previous character
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    // If current characters match, or pattern has '.', mark dp[i][j] as true
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // If pattern has '*', check two cases:
                    // 1. '*' matches zero occurrences of the previous character (dp[i][j-2])
                    // 2. '*' matches one or more occurrences of the previous character (dp[i-1][j])
                    dp[i][j] = dp[i][j - 2] || (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};
