/**
 * @file Day 7 Integer to English Words.cpp
 * @brief Solution to the LeetCode problem "Integer to English Words"
 * @link https://leetcode.com/problems/integer-to-english-words/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Convert a non-negative integer to its English words representation.
 * 
 * Approach:
 * - Use a series of helper functions to convert each group of digits (hundreds, thousands, millions, billions) into English words.
 * - Utilize maps to store the English words for digits, teens, and tens.
 * - Handle special cases such as zero.
 * 
 * Detailed Steps:
 * 1. Create a map for single digits and another map for tens.
 * 2. Define a helper function to convert up to three digits to English words.
 * 3. Process the number in chunks of three digits from right to left, appending the appropriate scale (thousand, million, billion) as necessary.
 * 4. Concatenate the results and trim any extra spaces.
 * 
 * Time Complexity:
 * - O(1), since the maximum number of digits is fixed (32-bit integer).
 * 
 * Space Complexity:
 * - O(1), as the space used is constant.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Trim from start (left)
    std::string ltrim(const std::string &s) {
        size_t start = s.find_first_not_of(" \t\n\r\f\v");
        return (start == std::string::npos) ? "" : s.substr(start);
    }

    // Trim from end (right)
    std::string rtrim(const std::string &s) {
        size_t end = s.find_last_not_of(" \t\n\r\f\v");
        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }

    // Trim from both ends
    std::string trim(const std::string &s) {
        return rtrim(ltrim(s));
    }

    unordered_map<int, vector<string>> one_place;
    unordered_map<int, string> second_place;

    const string hundy = "Hundred", thousand = "Thousand", million = "Million", billion = "Billion";

    /**
     * @brief Convert a three-digit number to English words
     * 
     * @param a The hundreds place digit
     * @param b The tens place digit
     * @param c The ones place digit
     * @return string The English words representation of the three-digit number
     */
    string convertToEnglish(int a, int b, int c) {
        if (a + b + c == 0) {
            return "";
        }
        string num = "";
        if (a != 0) {
            num += one_place[a][0] + " " + hundy + " ";
        } 
        if (b == 1) {
            num += one_place[c][1] + " ";
        } else if (b != 0) {
            num += second_place[b] + " " + one_place[c][0] + " ";
        } else {
            num += one_place[c][0] + " ";
        }

        return trim(num);
    }

    /**
     * @brief Convert an integer to its English words representation
     * 
     * @param num The integer to convert
     * @return string The English words representation of the integer
     */
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        one_place[0] = {"", "Ten"};
        one_place[1] = {"One", "Eleven"};
        one_place[2] = {"Two", "Twelve"};
        one_place[3] = {"Three", "Thirteen"};
        one_place[4] = {"Four", "Fourteen"};
        one_place[5] = {"Five", "Fifteen"};
        one_place[6] = {"Six", "Sixteen"};
        one_place[7] = {"Seven", "Seventeen"};
        one_place[8] = {"Eight", "Eighteen"};
        one_place[9] = {"Nine", "Nineteen"};

        second_place[00] = "";
        second_place[1] = "Ten";
        second_place[2] = "Twenty";
        second_place[3] = "Thirty";
        second_place[4] = "Forty";
        second_place[5] = "Fifty";
        second_place[6] = "Sixty";
        second_place[7] = "Seventy";
        second_place[8] = "Eighty";
        second_place[9] = "Ninety";

        vector<int> v;
        while (num) {
            v.push_back(num % 10);
            num /= 10;
        }
        int n = v.size();

        int bigWord = 1;
        vector<string> ans;

        for (int i = 0; i < n; i += 3) {
            int c = i < n ? v[i] : 0;
            int b = i + 1 < n ? v[i + 1] : 0;
            int a = i + 2 < n ? v[i + 2] : 0;

            string res = convertToEnglish(a, b, c);

            if (bigWord == 2 && res != "") {
                res += " " + thousand + " ";
            }
            if (bigWord == 3 && res != "") {
                res += " " + million + " ";
            }
            if (bigWord == 4 && res != "") {
                res += " " + billion + " ";
            }

            ans.push_back(trim(res));
            bigWord++;
        }

        string finalAns = "";

        for (int i = ans.size() - 1; i >= 0; i--) {
            if (ans[i] != "") {
                finalAns += ans[i] + " ";
            }
        }

        return trim(finalAns);
    }
};

