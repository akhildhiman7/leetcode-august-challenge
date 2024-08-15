/**
 * @file Day 13 Combination Sum II.cpp
 * @brief Solution to the LeetCode problem "Combination Sum II"
 * @link https://leetcode.com/problems/combination-sum-ii/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in 
 * `candidates` where the candidate numbers sum to `target`. Each number in `candidates` may only be used once in the combination.
 * 
 * Intuition:
 * This problem is a variation of the classic combination sum problem but with the additional constraint that each element 
 * can only be used once, and there may be duplicates in the input array. The key idea is to use backtracking to explore 
 * all possible combinations and ensure that we skip duplicates to avoid repeating the same combinations.
 * 
 * Approach:
 * - **Sort the Candidates:** Start by sorting the array. This makes it easier to skip duplicates and also helps to terminate 
 *   early when the remaining target becomes negative.
 * - **Backtracking:** Use a helper function to recursively explore all combinations. Start from a given index and explore 
 *   further by including the current element or moving to the next element.
 * - **Skip Duplicates:** To ensure each combination is unique, skip over duplicate elements in the sorted array.
 * 
 * Time Complexity:
 * - The time complexity is `O(2^n)`, where `n` is the number of candidates. This is due to the backtracking approach that 
 *   explores all possible combinations.
 * 
 * Space Complexity:
 * - The space complexity is `O(n)` for the recursion stack and additional space for storing the current combination.
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> result;
    
    /**
     * @brief Helper function to recursively find combinations.
     * 
     * @param candidates The list of candidate numbers.
     * @param start The current index in the candidates list.
     * @param target The remaining target sum.
     * @param current The current combination being explored.
     */
    void helper(std::vector<int>& candidates, int start, int target, std::vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue; // Skip duplicates

            current.push_back(candidates[i]);
            helper(candidates, i + 1, target - candidates[i], current);
            current.pop_back();
        }
    }

    /**
     * @brief Finds all unique combinations that sum up to the target.
     * 
     * @param candidates The list of candidate numbers.
     * @param target The target sum.
     * @return std::vector<std::vector<int>> A list of all unique combinations that sum up to the target.
     */
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<int> current;
        std::sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, current);
        return result;
    }
};

