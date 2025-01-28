#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') { // Find an empty cell
                    for (char num = '1'; num <= '9'; num++) { // Try numbers 1-9
                        if (isValid(board, row, col, num)) { // Check if the number is valid
                            board[row][col] = num; // Place the number
                            if (solve(board)) { // Recur to solve the rest of the board
                                return true;
                            }
                            board[row][col] = '.'; // Backtrack
                        }
                    }
                    return false; // If no number is valid, return false
                }
            }
        }
        return true; // Return true if the board is solved
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            // Check the row
            if (board[row][i] == num) return false;
            // Check the column
            if (board[i][col] == num) return false;
            // Check the 3x3 sub-grid
            if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == num) return false;
        }
        return true;
    }
};
