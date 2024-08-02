/**
 * @file Day 2 Number of Senior Citizens.cpp
 * @brief Solution to the LeetCode problem "Number of Senior Citizens"
 * @link https://leetcode.com/problems/number-of-senior-citizens/?envType=daily-question&envId=2024-08-01
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @brief Count the number of senior citizens (age > 60) from the provided details.
     *
     * This function iterates through the given vector of details and counts how many
     * individuals have an age greater than 60.
     *
     * @param details A vector of strings where each string contains personal details including age.
     * @return int The number of senior citizens (age > 60).
     */
    int countSeniors(vector<string>& details) {
        int count = 0;
        
        for (const auto& detail : details) {
            int age = (detail[11] - '0') * 10 + (detail[12] - '0');
            if (age > 60) {
                count++;
            }
        }
        
        return count;
    }
};

