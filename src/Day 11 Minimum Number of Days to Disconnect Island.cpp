/**
 * @file Day 11 Minimum Number of Days to Disconnect Island.cpp
 * @brief Solution to the LeetCode problem "Minimum Number of Days to Disconnect Island"
 * @link https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a 2D grid representing an island, determine the minimum number of days required to disconnect the island.
 * You can remove one or two land cells in a day. The island is considered disconnected if there are no connected
 * land cells remaining.
 * 
 * Intuition:
 * The approach involves checking the island's connectivity and trying to disconnect it by removing one or two cells.
 * First, we check if the island is already disconnected by counting the number of connected components (islands).
 * If not, we attempt to disconnect it by removing one cell at a time and checking the result.
 * 
 * Approach:
 * - Use Depth-First Search (DFS) to count the number of connected components in the grid.
 * - If the island is already disconnected (more than one component), return 0.
 * - Temporarily remove each land cell (set it to `0`) and check if the island becomes disconnected. If it does, return 1.
 * - If removing one cell doesn't work, return 2 since removing two cells will definitely disconnect the island.
 * 
 * Time Complexity:
 * - O(m * n), where `m` is the number of rows and `n` is the number of columns in the grid.
 * 
 * Space Complexity:
 * - O(m * n), due to the use of a copy of the grid for restoration purposes.
 */

#include <vector>
using namespace std;

class Solution {
public:
    // Depth-First Search to explore and mark connected components
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return;
        grid[i][j] = 0;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Step 1: Check if the grid is already disconnected
        int islandCount = 0;
        vector<vector<int>> gridCopy = grid;  // Make a copy of the grid
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++islandCount;
                    dfs(grid, i, j);
                }
            }
        }
        
        // If grid is already disconnected (no islands or multiple islands)
        if (islandCount != 1) {
            return 0;
        }
        
        // Restore the grid to its original state
        grid = gridCopy;
        
        // Step 2: Try removing one cell to disconnect the island
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;  // Temporarily remove the cell
                    
                    // Check if this removal disconnects the island
                    islandCount = 0;
                    for (int a = 0; a < m; ++a) {
                        for (int b = 0; b < n; ++b) {
                            if (grid[a][b] == 1) {
                                ++islandCount;
                                dfs(grid, a, b);
                            }
                        }
                    }
                    
                    if (islandCount != 1) {
                        return 1;  // The grid is disconnected by removing this one cell
                    }
                    
                    grid = gridCopy;  // Restore the grid
                }
            }
        }
        
        // Step 3: If removing one cell didn't work, removing two cells will always work
        return 2;
    }
};

