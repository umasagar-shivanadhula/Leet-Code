class Solution:
    def convert(self, s, numRows):
        if numRows == 1 or numRows >= len(s):
            return s
        
        # Create an array to hold each row of the zigzag pattern
        rows = [''] * numRows
        current_row = 0
        going_down = False
        
        # Traverse through the string
        for char in s:
            rows[current_row] += char
            # Change direction when reaching the top or bottom row
            if current_row == 0 or current_row == numRows - 1:
                going_down = not going_down
            # Move the row index up or down depending on the direction
            current_row += 1 if going_down else -1
        
        # Join all rows to get the final result
        return ''.join(rows)

# Example usage
s = "PAYPALISHIRING"
numRows = 3
solution = Solution()
result = solution.convert(s, numRows)

print(result)  # Output: "PAHNAPLSIIGYIR"
