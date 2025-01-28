class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def backtrack(current, open_count, close_count):
            # Base case: when the current string has reached the maximum length
            if len(current) == 2 * n:
                result.append(current)
                return
            
            # Add '(' if we have more open parentheses left to use
            if open_count < n:
                backtrack(current + "(", open_count + 1, close_count)
            
            # Add ')' if it is valid to close a previously opened parenthesis
            if close_count < open_count:
                backtrack(current + ")", open_count, close_count + 1)
        
        result = []
        backtrack("", 0, 0)
        return result

# Example usage
sol = Solution()
print(sol.generateParenthesis(3))  # Output: ["((()))", "(()())", "(())()", "()(())", "()()()"]
