/**
 * @file Day 1 Minimum Swaps to Group All 1's Together II.cpp
 * @brief Solution to the LeetCode problem "Minimum Swaps to Group All 1's Together II"
 * @link https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Calculate the minimum number of swaps required to group all 1s together in the given array.
     *
     * This function uses a sliding window approach to find the minimum number of swaps
     * needed to group all 1s in the array `nums`.
     *
     * @param nums The input vector of integers containing 0s and 1s.
     * @return int The minimum number of swaps required.
     */
    int minSwaps(vector<int>& nums) {
        int k = 0;             // Number of 1s in the input vector
        int zeroCount = 0;     // Number of 0s in the current window of size k
        int minSwaps = nums.size(); // Initialize minSwaps to the size of the vector

        // Count the number of 1s in the input vector
        for (const auto& num : nums) {
            if (num == 1) {
                k++;
            }
        }

        // Extend the vector to handle circular array cases
        nums.reserve(nums.size() * 2);
        nums.insert(nums.end(), nums.begin(), nums.end());

        // Count the number of 0s in the first window of size k
        for (int i = 0; i < k; i++) {
            if (nums[i] == 0) {
                zeroCount++;
            }
        }

        minSwaps = zeroCount; // Initialize minSwaps with the initial zero count

        // Slide the window over the extended vector
        for (int i = k; i < nums.size(); i++) {
            if (nums[i - k] == 0) {
                zeroCount--;
            }
            if (nums[i] == 0) {
                zeroCount++;
            }
            minSwaps = min(minSwaps, zeroCount);
        }

        return minSwaps;
    }
};

