/**
 * @file Day 22 Number Complement.cpp
 * @brief Solution to the LeetCode problem "Number Complement"
 * @link https://leetcode.com/problems/number-complement/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a positive integer `num`, output its complement number. The complement strategy is to flip the bits of its binary representation.
 * 
 * Intuition:
 * The goal is to flip the bits of `num`'s binary representation. The most straightforward approach is to iterate over each bit, flipping it until we reach the most significant bit.
 * 
 * Approach:
 * - **Bit Manipulation:** Iterate through each bit of the number, flipping each `0` to `1` while keeping track of the position using bitwise operations. The final result is the complement of the number.
 * 
 * Time Complexity:
 * - O(log n), where `n` is the given number. This is because we iterate through each bit of the number.
 * 
 * Space Complexity:
 * - O(1), since only a few variables are used to store intermediate results.
 */

#include <cmath>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int place = 0;
        int ans = 0;

        while (num > 0) {
            int digit = num & 1;
            num = num >> 1;

            if (!digit) {
                ans += 1 << place;
            }

            place++;
        }

        return ans;
    }
};

