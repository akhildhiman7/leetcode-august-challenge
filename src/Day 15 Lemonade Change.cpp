/**
 * @file Day 15 Lemonade Change.cpp
 * @brief Solution to the LeetCode problem "Lemonade Change"
 * @link https://leetcode.com/problems/lemonade-change/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * You are given an integer array `bills` where `bills[i]` can be 5, 10, or 20 dollars. You start with no change in hand.
 * Return `true` if you can provide every customer with the correct change, or `false` otherwise.
 * 
 * Intuition:
 * The core idea is to simulate the process of giving change to customers. You need to keep track of the number of 5-dollar 
 * and 10-dollar bills you have because the 5-dollar bill is crucial for making change, and the 10-dollar bill can help minimize 
 * the number of 5-dollar bills you use.
 * 
 * Approach:
 * - Iterate through the list of bills.
 * - For each bill:
 *   - If the bill is $5, increase the count of 5-dollar bills.
 *   - If the bill is $10, ensure you can give back $5 in change (check if you have a 5-dollar bill), and update the counts accordingly.
 *   - If the bill is $20, prioritize giving back a $10 and a $5 bill as change. If that’s not possible, give back three $5 bills.
 * - If at any point you cannot give the correct change, return `false`.
 * 
 * Time Complexity:
 * - O(n), where `n` is the number of bills. We iterate through the list of bills once.
 * 
 * Space Complexity:
 * - O(1), as only a fixed amount of extra space is used to store the counts of 5-dollar and 10-dollar bills.
 */

#include <vector>

class Solution {
public:
    /**
     * @brief Determines if you can provide correct change for each customer.
     * 
     * @param bills The list of bills given by customers.
     * @return bool Returns true if you can provide change for each customer, otherwise false.
     */
    bool lemonadeChange(std::vector<int>& bills) {
        int fiveCount = 0, tenCount = 0;
        
        for (auto &dollar : bills) {
            if (dollar == 5) {
                fiveCount++;
            } else if (dollar == 10) {
                if (fiveCount < 1) {
                    return false;
                }
                fiveCount--;
                tenCount++;
            } else {
                if (tenCount >= 1 && fiveCount >= 1) {
                    fiveCount--;
                    tenCount--;
                } else if (fiveCount >= 3) {
                    fiveCount -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};

