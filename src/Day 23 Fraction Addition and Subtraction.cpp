/**
 * @file Day 23 Fraction Addition and Subtraction.cpp
 * @brief Solution to the LeetCode problem "Fraction Addition and Subtraction"
 * @link https://leetcode.com/problems/fraction-addition-and-subtraction/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a string representing an expression of fractions separated by addition and subtraction operators, 
 * calculate the result of the expression and return it in its simplest form.
 * 
 * Intuition:
 * The problem requires parsing and evaluating arithmetic expressions that involve fractions. The task is to 
 * parse the fractions from the string, handle negative signs, and compute the sum of all fractions while 
 * reducing the result to its simplest form using the greatest common divisor (GCD).
 * 
 * Approach:
 * - **Parsing the Expression:** Use a helper function `parseExpression` to split the input string into individual 
 *   fractions and integers based on the provided delimiter. This function also populates a vector with parsed integers if needed.
 * - **Handling Negative Values:** Use `parseNegativeValue` to handle the parsing of fractions that may have negative signs. 
 *   This function breaks down the string into manageable pieces.
 * - **Finding GCD:** Implement a simple GCD function, `findGCD`, to reduce fractions to their simplest form.
 * - **Solving Fraction Operations:** The function `solveTwoFractions` computes the result of adding two fractions together. 
 *   It handles cases where fractions have the same or different denominators, and it uses the GCD to simplify the result.
 * - **Main Function:** The `fractionAddition` function integrates all these helper functions to parse the input expression, 
 *   compute the sum of fractions, and return the final result as a string in the form "numerator/denominator".
 * 
 * Time Complexity:
 * - O(n), where `n` is the length of the input string. The operations for parsing, GCD calculation, and fraction addition are linear.
 * 
 * Space Complexity:
 * - O(n), for storing parsed fractions and intermediate results.
 */

#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Solution {
public:
    // Helper function to parse expressions and optionally convert to integers
    vector<string> parseExpression(string expression, char del, int mode, vector<int> &v) {
        stringstream ss(expression);
        string token;
        vector<string> res;
        
        while (getline(ss, token, del)) {
            res.push_back(token);
            if (mode == 1) {
                v.push_back(stoi(token));
            }
        }
        
        return res;
    }
    
    // Parse fractions that may contain negative values
    vector<vector<int>> parseNegativeValue(string expression) {
        vector<vector<int>> v;
        int i = 0;
        while (i < expression.size()) {
            int j = i + 1;
            while (j < expression.size() && expression[j] != '-') {
                j++;
            }
            string s = expression.substr(i, j - i);
            if (!s.empty()) {
                vector<int> temp;
                parseExpression(s, '/', 1, temp);
                v.push_back(temp);
            }
            i = j;
        }
        return v;
    }
    
    // Find the Greatest Common Divisor (GCD)
    int findGCD(int a, int b) {
        int x = min(a, b);
        int lastMul = 1;
        for (int i = 1; i <= x; i++) {
            if (a % i == 0 && b % i == 0) {
                lastMul = i;
            }
        }
        return lastMul;
    }
    
    // Solve the addition of two fractions
    vector<int> solveTwoFractions(vector<int> &a, vector<int> &b) {
        int num1 = a[0], den1 = a[1];
        int num2 = b[0], den2 = b[1];
        
        if (num1 == 0) {
            return b;
        }
        
        int p, q;
        if (den1 == den2) {
            p = num1 + num2;
            q = den2;
        } else {
            p = (num1 * den2) + (num2 * den1);
            q = den1 * den2;
        }
        
        int gcd = findGCD(abs(p), abs(q));
        return {p / gcd, q / gcd};
    }
    
    // Main function to perform fraction addition and subtraction
    string fractionAddition(string expression) {
        vector<int> temp;
        vector<string> v = parseExpression(expression, '+', 0, temp);
        
        vector<vector<int>> fractions;
        
        for (auto &e: v) {
            vector<vector<int>> temp = parseNegativeValue(e);
            fractions.insert(fractions.end(), temp.begin(), temp.end());
        }
        
        vector<int> res = fractions[0];
        
        for (int i = 1; i < fractions.size(); i++) {
            res = solveTwoFractions(res, fractions[i]);
        }
        
        res[1] = res[0] == 0 ? 1 : res[1];
        
        return to_string(res[0]) + "/" + to_string(res[1]);
    }
};

