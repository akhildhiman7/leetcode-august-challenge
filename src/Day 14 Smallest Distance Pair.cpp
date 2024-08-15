/**
 * @file Day 14 Smallest Distance Pair.cpp
 * @brief Solution to the LeetCode problem "Find K-th Smallest Pair Distance"
 * @link https://leetcode.com/problems/find-k-th-smallest-pair-distance/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given an integer array `nums` and an integer `k`, return the `k`-th smallest distance among all the pairs in `nums`. 
 * The distance of a pair `(nums[i], nums[j])` is defined as `|nums[i] - nums[j]|`, where `i < j`.
 * 
 * Intuition:
 * The problem can be solved using a combination of sorting and binary search. After sorting the array, the problem becomes 
 * finding the smallest pair difference that has exactly `k` pairs less than or equal to it. Binary search can efficiently 
 * find this value.
 * 
 * Approach:
 * - **Sorting:** Start by sorting the array `nums`. This allows us to easily calculate the pairwise differences and apply 
 *   binary search on the difference.
 * - **Binary Search:** Perform binary search on the range of possible pair distances (from `0` to `max(nums) - min(nums)`).
 *   For each midpoint in this range, count how many pairs have a difference less than or equal to this midpoint. If the 
 *   count is less than `k`, move the search to the right half (increase the minimum difference). Otherwise, move the search 
 *   to the left half.
 * - **Counting Pairs:** Use two pointers to count the number of pairs that have a difference less than or equal to a given value.
 * 
 * Time Complexity:
 * - Sorting the array takes `O(n log n)`.
 * - Binary search is performed on the difference range, and for each midpoint, counting pairs takes `O(n)`. Therefore, the 
 *   total time complexity is `O(n log n + n log d)` where `d` is the difference between the maximum and minimum elements.
 * 
 * Space Complexity:
 * - The space complexity is `O(1)` for the binary search and pair counting, with `O(n)` used by the sorting algorithm.
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * @brief Count the number of pairs with a distance less than or equal to 'mid'.
     * 
     * @param nums The sorted array of integers.
     * @param mid The current midpoint of the binary search.
     * @return int The number of pairs with a distance less than or equal to 'mid'.
     */
    int getNumPairs(std::vector<int>& nums, int mid) {
        int left = 0, right = 1, totalPairs = 0;
        
        while (right < nums.size()) {
            while (right > left && nums[right] - nums[left] > mid) {
                left++;
            }
            totalPairs += right - left;
            right++;
        }
        
        return totalPairs;
    }
    
    /**
     * @brief Find the k-th smallest pair distance in the array.
     * 
     * @param nums The input array of integers.
     * @param k The k-th smallest distance to find.
     * @return int The k-th smallest pair distance.
     */
    int smallestDistancePair(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int start = 0, end = nums[nums.size() - 1] - nums[0];
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int numPairs = getNumPairs(nums, mid);
            
            if (numPairs < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return start;
    }
};

