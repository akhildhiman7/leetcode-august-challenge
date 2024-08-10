/**
 * @file Day 10 Regions Cut By Slashes.cpp
 * @brief Solution to the LeetCode problem "Regions Cut By Slashes"
 * @link https://leetcode.com/problems/regions-cut-by-slashes/
 * 
 * Problem Statement:
 * Given a grid of strings representing slashes (`/`), backslashes (`\`), and spaces (` `), 
 * determine the number of regions formed by the slashes. A region is a group of connected cells.
 * 
 * Intuition:
 * Each cell in the grid can be conceptually divided into four parts:
 * - Top-left
 * - Top-right
 * - Bottom-left
 * - Bottom-right
 * 
 * Slashes (`/`) and backslashes (`\`) divide these cells:
 * - A `/` separates the top-left from the bottom-right.
 * - A `\` separates the top-right from the bottom-left.
 * 
 * The key idea is to use DFS (Depth-First Search) to explore these segments and count how many distinct regions they form. 
 * A lookup map tracks which parts of each cell have been visited to ensure that each region is counted only once.
 * 
 * Approach:
 * - Treat each cell as having two potential regions that can be split by a slash or backslash.
 * - Use a lookup map to track which parts of each cell have been visited (e.g., top-left or bottom-right).
 * - Perform DFS to explore all connected regions and count each new region discovered.
 * - The lookup map ensures that we correctly count each region only once.
 * 
 * Time Complexity:
 * - O(n * m), where n is the number of rows and m is the number of columns in the grid.
 * 
 * Space Complexity:
 * - O(n * m), for the DFS stack and the lookup map.
 */

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int m, n;  // Dimensions of the grid
    unordered_map<string, pair<int, int>> lookup;  // Map to track visited segments of cells

    /**
     * @brief Generates a unique key for each cell in the grid.
     * @param i Row index
     * @param j Column index
     * @return A string key representing the cell's coordinates
     */
    string key(int &i, int &j) {
        return to_string(i) + "," + to_string(j);
    }

    /**
     * @brief DFS function to explore regions in the grid.
     * @param grid The grid to explore
     * @param i Current row index
     * @param j Current column index
     * @param a Previous row index (for directional checks)
     * @param b Previous column index (for directional checks)
     * 
     * This function handles the exploration of regions by considering the top-left, top-right, bottom-left,
     * and bottom-right parts of each cell, depending on whether the cell contains a slash (`/`), backslash (`\`), 
     * or is empty.
     */
    void dfs(vector<string> &grid, int i, int j, int a, int b) {
        // Boundary check and base case for DFS
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '-') {
            return;
        }

        string lookupKey = key(i, j);
        pair<int, int> p = lookup.count(lookupKey) ? lookup[lookupKey] : make_pair(0, 0);

        // Handle slashes ('/')
        if (grid[i][j] == '/') {
            if (a + 1 == i || b + 1 == j) {  // Moving down or right (top-left region)
                if (p.first) return;  // If top-left region already visited
                p.first = 1;  // Mark top-left as visited
                lookup[lookupKey] = p;
                if (a + 1 == i) dfs(grid, i, j - 1, i, j);  // Continue DFS to the left
                else dfs(grid, i - 1, j, i, j);  // Continue DFS upwards
            } else {  // Moving up or left (bottom-right region)
                if (p.second) return;  // If bottom-right region already visited
                p.second = 1;  // Mark bottom-right as visited
                lookup[lookupKey] = p;
                if (j == b - 1) dfs(grid, i + 1, j, i, j);  // Continue DFS downwards
                else dfs(grid, i, j + 1, i, j);  // Continue DFS to the right
            }
            return;
        } 
        // Handle backslashes ('\')
        else if (grid[i][j] == '\\') {
            if (a + 1 == i || b - 1 == j) {  // Moving down or left (top-right region)
                if (p.first == 1) return;  // If top-right region already visited
                p.first = 1;  // Mark top-right as visited
                lookup[lookupKey] = p;
                if (a + 1 == i) dfs(grid, i, j + 1, i, j);  // Continue DFS to the right
                else dfs(grid, i - 1, j, i, j);  // Continue DFS upwards
            } else {  // Moving up or right (bottom-left region)
                if (p.second == 1) return;  // If bottom-left region already visited
                p.second = 1;  // Mark bottom-left as visited
                lookup[lookupKey] = p;
                if (b + 1 == j) dfs(grid, i + 1, j, i, j);  // Continue DFS downwards
                else dfs(grid, i, j - 1, i, j);  // Continue DFS to the left
            }
            return;
        } 
        // Handle spaces (' ')
        else {
            grid[i][j] = '-';  // Mark the whole cell as visited
        }

        // Continue DFS in all four directions from the current cell
        dfs(grid, i + 1, j, i, j);  // Down
        dfs(grid, i - 1, j, i, j);  // Up
        dfs(grid, i, j + 1, i, j);  // Right
        dfs(grid, i, j - 1, i, j);  // Left
    }

    /**
     * @brief Main function to count regions divided by slashes.
     * @param grid The input grid
     * @return The number of regions
     */
    int regionsBySlashes(vector<string>& grid) {
        int totalRegions = 0;
        m = grid.size();
        n = grid[0].size();

        // Iterate over each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == ' ') {  // If the cell is empty
                    dfs(grid, i, j, i, j);  // Perform DFS to explore the region
                    totalRegions++;  // Increment region count
                } 
                else if (grid[i][j] == '/') {  // If the cell contains a '/'
                    string lookupKey = key(i, j);
                    pair<int, int> p = lookup.count(lookupKey) ? lookup[lookupKey] : make_pair(0, 0);
                    if (p.first != 1) {  // If the top-left region hasn't been visited
                        p.first = 1;
                        lookup[lookupKey] = p;
                        dfs(grid, i - 1, j, i, j);  // Explore the region upwards
                        dfs(grid, i, j - 1, i, j);  // Explore the region to the left
                        totalRegions++;
                    } 
                    p = lookup[lookupKey];
                    if (p.second != 1) {  // If the bottom-right region hasn't been visited
                        p.second = 1;
                        lookup[lookupKey] = p;
                        dfs(grid, i, j + 1, i, j);  // Explore the region to the right
                        dfs(grid, i + 1, j, i, j);  // Explore the region downwards
                        totalRegions++;
                    }
                } 
                else if (grid[i][j] == '\\') {  // If the cell contains a '\\'
                    string lookupKey = key(i, j);
                    pair<int, int> p = lookup.count(lookupKey) ? lookup[lookupKey] : make_pair(0, 0);
                    if (p.first != 1) {  // If the top-right region hasn't been visited
                        p.first = 1;
                        lookup[lookupKey] = p;
                        dfs(grid, i - 1, j, i, j);  // Explore the region upwards
                        dfs(grid, i, j + 1, i, j);  // Explore the region to the right
                        totalRegions++;
                    }
                    p = lookup[lookupKey];
                    if (p.second != 1) {  // If the bottom-left region hasn't been visited
                        p.second = 1;
                        lookup[lookupKey] = p;
                        dfs(grid, i + 1, j, i, j);  // Explore the region downwards
                        dfs(grid, i, j - 1, i, j);  // Explore the region to the left
                        totalRegions++;
                    }
                }
            }
        }

        return totalRegions;
    }
};

