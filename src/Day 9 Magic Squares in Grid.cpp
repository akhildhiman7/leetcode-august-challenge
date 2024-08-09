/**
 * @file Day 9 Magic Squares in Grid.cpp
 * @brief Solution to the LeetCode problem "Magic Squares in Grid"
 * @link https://leetcode.com/problems/magic-squares-in-grid/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a grid of integers, determine the number of 3x3 subgrids that form a magic square. A magic square is a 3x3 grid where the sum of each row, column, and both diagonals is the same, and all elements are distinct numbers from 1 to 9.
 * 
 * Intuition:
 * The core idea is to examine each 3x3 subgrid within the given grid and check whether it satisfies the properties of a magic square. Since the grid can have multiple 3x3 subgrids, we slide a 3x3 window over the grid, checking each possible subgrid.
 * 
 * Approach:
 * - Iterate through each possible top-left corner of a 3x3 subgrid within the given grid.
 * - For each subgrid, calculate the sum of the rows, columns, and diagonals.
 * - Check whether all the calculated sums are equal and whether all numbers in the subgrid are distinct and in the range from 1 to 9.
 * - Count the number of subgrids that satisfy these conditions.
 * 
 * Time Complexity:
 * - O(n * m), where n is the number of rows and m is the number of columns in the grid.
 * 
 * Space Complexity:
 * - O(1), as we are only using a fixed amount of extra space.
 */

#include <vector>
using namespace std;

class Solution {
public:
    // Function to check if a 3x3 grid is a magic square
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        vector<int> nums(10, 0);
        
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        // Check rows
        for (int i = 0; i < 3; ++i) {
            int rowSum = grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2];
            if (rowSum != sum) return false;
        }
        // Check columns
        for (int i = 0; i < 3; ++i) {
            int colSum = grid[row][col+i] + grid[row+1][col+i] + grid[row+2][col+i];
            if (colSum != sum) return false;
        }
        // Check diagonals
        int diag1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int diag2 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        if (diag1 != sum || diag2 != sum) return false;

        // Check if all numbers are distinct and in the range 1-9
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int val = grid[row+i][col+j];
                if (val < 1 || val > 9 || nums[val] == 1) return false;
                nums[val] = 1;
            }
        }

        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (isMagicSquare(grid, i, j)) {
                    ++count;
                }
            }
        }
        
        return count;
    }
};

