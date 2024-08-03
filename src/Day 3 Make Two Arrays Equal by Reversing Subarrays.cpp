/**
 * @file Day 3 Make Two Arrays Equal by Reversing Subarrays.cpp
 * @brief Solution to the LeetCode problem "Make Two Arrays Equal by Reversing Subarrays"
 * @link https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * @brief Check if two arrays can be made equal by reversing subarrays.
     *
     * This function uses a hashmap to count the occurrences of each element in the `arr` array,
     * and then checks if the `target` array can be constructed using the same elements.
     *
     * @param target The target vector of integers.
     * @param arr The input vector of integers.
     * @return bool True if the two arrays can be made equal by reversing subarrays, false otherwise.
     */
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> elementCount;

        // Count occurrences of each element in arr
        for (const auto& num : arr) {
            elementCount[num]++;
        }

        // Check if target can be constructed using the elements in arr
        for (const auto& num : target) {
            if (elementCount.find(num) == elementCount.end() || elementCount[num] == 0) {
                return false;
            }
            elementCount[num]--;
        }

        return true;
    }
};

