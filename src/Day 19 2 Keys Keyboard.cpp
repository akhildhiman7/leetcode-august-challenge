/**
 * @file Day 19 2 Keys Keyboard.cpp
 * @brief Solution to the LeetCode problem "2 Keys Keyboard"
 * @link https://leetcode.com/problems/2-keys-keyboard/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * You start with a single character 'A' on a screen and can perform two operations:
 * 1. Copy All: Copy all characters currently on the screen to a buffer.
 * 2. Paste: Paste the characters in the buffer onto the screen.
 * 
 * Given an integer `n`, return the minimum number of steps to get exactly `n` 'A' characters on the screen.
 * 
 * Intuition:
 * The problem can be solved using a recursive approach with a helper function to explore all possible ways
 * to achieve exactly `n` 'A' characters. The idea is to either double the current number of characters on the screen
 * by copying and pasting or incrementally add characters by pasting from the buffer. The goal is to minimize the 
 * number of operations required.
 * 
 * Approach:
 * - **Recursive Approach:** The recursive function `helper` explores two options at each step: either doubling the 
 *   current number of characters on the screen (by copying and pasting) or adding the number of characters in the 
 *   buffer to the screen (by pasting). The function returns the minimum number of steps required to reach exactly `n`.
 * 
 * Time Complexity:
 * - O(n^2), where `n` is the number of characters needed on the screen. The recursive function explores all possible 
 *   combinations of screen and buffer values.
 * 
 * Space Complexity:
 * - O(n), for the recursive call stack.
 */

#include <algorithm>

using namespace std;

class Solution {
public:
    int helper(int screen, int buffer, int n) {
        // Base case: if screen has exactly n characters
        if (screen == n) {
            return 0;
        } 
        // If screen exceeds n or buffer is already larger than needed
        else if (screen > n || buffer >= n) {
            return 1000;  // Use a large number to indicate an invalid path
        }
        
        // Recursively calculate the minimum steps required
        return min(2 + helper(screen * 2, screen, n), 1 + helper(screen + buffer, buffer, n));
    }
    
    int minSteps(int n) {
        if (n == 1) return 0;  // No steps needed if n is 1
        return 1 + helper(1, 1, n);  // Start with one 'A' on screen and buffer
    }
};

