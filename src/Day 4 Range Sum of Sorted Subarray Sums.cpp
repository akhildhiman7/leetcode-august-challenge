/**
 * @file Day 4 Range Sum of Sorted Subarray Sums.cpp
 * @brief Solution to the LeetCode problem "Range Sum of Sorted Subarray Sums"
 * @link https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/?envType=daily-question&envId=2024-08-04
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given the array nums consisting of n positive integers and two positive integers left and right (1 <= left <= right <= n * (n + 1) / 2), 
 * return the sum of the numbers from the left-th smallest to the right-th smallest subarray sums.
 * Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * To solve this problem, we can use the following approach:
 * 1. Generate all possible subarray sums and store them in a new array.
 * 2. Sort the array of subarray sums.
 * 3. Sum the elements from the (left-1)-th index to the (right-1)-th index of the sorted array.
 * 4. Return the sum modulo 10^9 + 7.
 * 
 * The time complexity of this approach is O(n^2 log(n^2)) due to the generation and sorting of subarray sums.
 */

#include <vector>
#include <algorithm>

#define MOD_VAL 1000000007

using namespace std;

class Solution {
public:
    /**
     * @brief Computes the range sum of sorted subarray sums.
     * 
     * @param nums The input vector of positive integers.
     * @param n The length of the input vector.
     * @param left The starting index of the range (1-based).
     * @param right The ending index of the range (1-based).
     * @return int The range sum of sorted subarray sums modulo 10^9 + 7.
     */
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarraySums;
        
        // Generate all possible subarray sums
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum = (sum + nums[j]) % MOD_VAL;
                subarraySums.push_back(sum);
            }
        }
        
        // Sort the array of subarray sums
        sort(subarraySums.begin(), subarraySums.end());
        
        // Compute the range sum
        int totalSum = 0;
        for (int i = left - 1; i < right; i++) {
            totalSum = (totalSum + subarraySums[i]) % MOD_VAL;
        }
        
        return totalSum;
    }
};

