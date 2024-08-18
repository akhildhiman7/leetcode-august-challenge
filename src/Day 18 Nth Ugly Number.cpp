/**
 * @file Day 18 Nth Ugly Number.cpp
 * @brief Solution to the LeetCode problem "Nth Ugly Number"
 * @link https://leetcode.com/problems/nth-ugly-number/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5. Given an integer `n`, 
 * return the `n`-th ugly number in ascending order.
 * 
 * Intuition:
 * The problem can be solved efficiently using a min-heap (priority queue) to generate the sequence of ugly numbers.
 * Starting with the smallest ugly number, 1, we generate the next ugly numbers by multiplying the current number 
 * by 2, 3, and 5. The heap allows us to efficiently get the smallest available ugly number, ensuring the sequence 
 * is generated in increasing order. We use a set to avoid duplicates.
 * 
 * Approach:
 * - **Min-Heap:** We use a min-heap (priority queue) to keep track of the next smallest ugly number.
 * - **Set for Deduplication:** We use a set to ensure no duplicate numbers are added to the heap.
 * - **Heap Operations:** We push 1 into the heap and then iteratively pop the smallest number, generating the next 
 *   ugly numbers by multiplying it by 2, 3, and 5. The loop runs until we extract the `n`-th ugly number from the heap.
 * 
 * Time Complexity:
 * - O(n * log n), where `n` is the number of ugly numbers to be generated. The log factor comes from the heap operations.
 * 
 * Space Complexity:
 * - O(n), due to the heap and the set used to store the ugly numbers.
 */

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 6) {
            return n;
        }
        
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        unordered_set<long long> seen;
        
        // Initial ugly number
        minHeap.push(1);
        seen.insert(1);
        
        long long currNum;
        
        for (int i = 0; i < n; ++i) {
            currNum = minHeap.top();
            minHeap.pop();
            
            // Generate next ugly numbers by multiplying with 2, 3, and 5
            if (seen.insert(currNum * 2).second) {
                minHeap.push(currNum * 2);
            }
            if (seen.insert(currNum * 3).second) {
                minHeap.push(currNum * 3);
            }
            if (seen.insert(currNum * 5).second) {
                minHeap.push(currNum * 5);
            }
        }
        
        return static_cast<int>(currNum);
    }
};

