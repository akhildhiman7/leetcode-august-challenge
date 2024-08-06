/**
 * @file Day 6 Minimum Number of Pushes to Type Word II.cpp
 * @brief Solution to the LeetCode problem "Minimum Number of Pushes to Type Word II"
 * @link https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a string `word`, you are to type it using a keyboard where each key press has a different cost.
 * The cost to press a character depends on how many times it has been pressed before. The cost of the first 
 * press is 1, the cost of the second press is 2, and so on.
 * 
 * Approach:
 * - Count the frequency of each character in the word.
 * - Sort the frequencies in descending order to minimize the total cost.
 * - Assign the cost starting from 1 and increasing by 1 after every 8 characters.
 * - Sum up the total cost.
 * 
 * Detailed Steps:
 * 1. Create an array `nums` of size 26 to store the frequency of each character.
 * 2. Iterate through the word and increment the count of the corresponding character in the `nums` array.
 * 3. Sort the `nums` array in descending order.
 * 4. Initialize `minPresses` to 0 to store the total minimum presses.
 * 5. Initialize `press` to 1 to store the current cost of pressing a character.
 * 6. Iterate through the `nums` array in chunks of 8:
 *    - For each chunk, add the product of the frequency and the current cost to `minPresses`.
 *    - Increment the cost for the next chunk.
 * 7. Return the total minimum presses.
 * 
 * Time Complexity:
 * - O(n + k log k), where n is the length of the word and k is the number of unique characters (at most 26).
 * 
 * Space Complexity:
 * - O(1), as we are using a constant amount of extra space.
 */

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @brief Determines the minimum number of presses to type the given word.
     * 
     * @param word The input string representing the word to be typed
     * @return int The minimum number of presses required
     */
    int minimumPushes(string word) {
        vector<int> nums(26, 0);
        
        // Count the frequency of each character
        for (auto &chr : word) {
            nums[chr - 'a']++;
        }
        
        // Sort the frequencies in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        
        int minPresses = 0;
        int press = 1;
        
        // Calculate the total minimum presses
        for (int i = 0; i < 26; i += 8) {
            int n = min(i + 8, 26);
            for (int j = i; j < n; j++) {
                minPresses += nums[j] * press;
            }
            press++;
        }
        
        return minPresses;
    }
};

