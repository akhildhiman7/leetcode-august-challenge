/**
 * @file Day 17 Maximum Number of Points with Cost.cpp
 * @brief Solution to the LeetCode problem "Maximum Number of Points with Cost"
 * @link https://leetcode.com/problems/maximum-number-of-points-with-cost/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given an `m x n` matrix `points` where each element represents the points you can earn by choosing it, 
 * you start at the top row and choose one element from each row. However, moving from one element to 
 * another in the next row incurs a cost equal to the absolute difference in column indices.
 * Return the maximum number of points you can achieve.
 * 
 * Intuition:
 * The problem is a variation of the dynamic programming (DP) pathfinding problem where each move from 
 * one row to another incurs a cost based on the difference in column indices. The goal is to accumulate 
 * the maximum points while minimizing the cost. A naive recursive solution would explore all possibilities, 
 * but this can be optimized using dynamic programming.
 * 
 * Approach:
 * - **Recursive Approach:** Use a recursive function with memoization to explore all possible paths from 
 *   the top row to the bottom. For each cell in the current row, calculate the maximum points by moving 
 *   to any cell in the next row and subtracting the movement cost. Memoize results to avoid recomputation.
 * - **Iterative Approach:** The iterative DP approach involves calculating the maximum points row by row. 
 *   For each cell, calculate the best possible points by considering the maximum points achievable from 
 *   the previous row while considering the movement cost. To efficiently calculate the maximum points 
 *   for each cell, two auxiliary arrays (leftSum and rightSum) are used to precompute the maximum values 
 *   from left to right and right to left.
 * 
 * Time Complexity:
 * - **Recursive Approach:** The time complexity is `O(m * n^2)` where `m` is the number of rows and `n` 
 *   is the number of columns. This is because the recursive approach explores all possible paths.
 * - **Iterative Approach:** The time complexity is `O(m * n)` as each cell is processed once per row, 
 *   with efficient calculation of maximum values.
 * 
 * Space Complexity:
 * - The space complexity is `O(m * n)` due to the DP table used to store results for each cell.
 */

#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxSum = 0;

    long long helper(vector<vector<int>>& points, int i, int j, vector<vector<long long>>& dp) {
        if (i >= points.size() && j == points[i].size() || j < 0) {
            return 0;
        } else if (i == points.size() - 1) {
            return points[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        long long temp = 0;

        for (int q = 0; q < points[i].size(); q++) {
            temp = max(temp, helper(points, i + 1, q, dp) - abs(j - q));
        }

        return dp[i][j] = points[i][j] + temp;
    }

    long long recursive(vector<vector<int>>& points) {
        long long maxSum = 0;
        vector<vector<long long>> dp(points.size(), vector<long long>(points[0].size(), -1));

        for (int j = 0; j < points[0].size(); j++) {
            maxSum = max(maxSum, helper(points, 0, j, dp));
        }

        return maxSum;
    }

    long long iterative(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = points[0][j];
        }

        for (int i = 1; i < m; i++) {
            vector<long long> leftSum(n, 0), rightSum(n, 0);
            leftSum[0] = dp[i - 1][0];
            rightSum[n - 1] = dp[i - 1][n - 1];

            for (int a = 1; a < n; a++) {
                leftSum[a] = max(leftSum[a - 1] - 1, dp[i - 1][a]);
                rightSum[n - a - 1] = max(rightSum[n - a] - 1, dp[i - 1][n - a - 1]);
            }

            for (int a = 0; a < n; a++) {
                if (a > 0 && a < n - 1) {
                    dp[i][a] = points[i][a] + max(leftSum[a], max(leftSum[a - 1] - 1, max(rightSum[a], rightSum[a + 1] - 1)));
                } else if (a == 0) {
                    dp[i][0] = points[i][0] + max(leftSum[0], rightSum[1] - 1);
                } else {
                    dp[i][n - 1] = points[i][n - 1] + max(rightSum[n - 1], leftSum[n - 2] - 1);
                }
            }
        }

        return *max_element(dp[m - 1].begin(), dp[m - 1].end());
    }

    long long maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1) {
            return *max_element(points[0].begin(), points[0].end());
        } else if (points[0].size() == 1) {
            long long sum = 0;
            for (int i = 0; i < points.size(); i++) {
                sum += points[i][0];
            }
            return sum;
        }
        return iterative(points);
    }
};

