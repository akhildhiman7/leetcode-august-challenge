/**
 * @file Day 8 Spiral Matrix III.cpp
 * @brief Solution to the LeetCode problem "Spiral Matrix III"
 * @link https://leetcode.com/problems/spiral-matrix-iii/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given the dimensions of a matrix `rows` and `cols`, and a starting point `(rStart, cStart)`, return all the cells in the matrix in the order they are visited in a spiral order, starting from the given starting cell.
 * 
 * Intuition:
 * The key intuition is to simulate walking in a spiral path starting from the given coordinates `(rStart, cStart)`. We repeatedly expand the spiral by alternating between moving right, down, left, and up, with each movement extending one unit further than the last in each direction.
 * 
 * Approach:
 * - Start from the given starting cell `(rStart, cStart)`.
 * - Use a direction array to facilitate right, down, left, and up movements.
 * - Ensure each visited cell is within the matrix bounds before adding it to the result list.
 * - Increment the number of steps in each direction after every two direction changes.
 * 
 * Time Complexity:
 * - O(rows * cols), since we visit each cell in the matrix exactly once.
 * 
 * Space Complexity:
 * - O(1), excluding the space required for the output result.
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        result.push_back({rStart, cStart});
        
        // Direction vectors for right, down, left, and up movements
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int numSteps = 1; // Initial number of steps in each direction
        int d = 0; // Start with moving right
        
        while (result.size() < rows * cols) {
            // Traverse in the current direction
            for (int i = 0; i < numSteps; ++i) {
                rStart += directions[d].first;
                cStart += directions[d].second;
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    result.push_back({rStart, cStart});
                }
            }
            
            // Change direction
            d = (d + 1) % 4;
            
            // Increase steps after completing two directions (right-down, left-up)
            if (d == 0 || d == 2) {
                numSteps++;
            }
        }
        
        return result;
    }
};

