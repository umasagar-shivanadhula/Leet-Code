class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = [-1]  # Initialize the stack with -1 to handle edge cases
        max_len = 0  # Variable to store the maximum valid length
        
        for i in range(len(s)):
            if s[i] == '(':  # Push the index of '(' onto the stack
                stack.append(i)
            else:  # When encountering ')'
                stack.pop()  # Pop the top element (which represents a matching '(')
                
                if not stack:  # If the stack is empty, push the current index as a base for future substrings
                    stack.append(i)
                else:
                    # Calculate the length of the current valid substring
                    max_len = max(max_len, i - stack[-1])
        
        return max_len
