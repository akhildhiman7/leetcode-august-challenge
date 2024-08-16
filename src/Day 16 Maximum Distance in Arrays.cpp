/**
 * @file Day 16 Maximum Distance in Arrays.cpp
 * @brief Solution to the LeetCode problem "Maximum Distance in Arrays"
 * @link https://leetcode.com/problems/maximum-distance-in-arrays/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a list of arrays, each array is sorted in non-decreasing order. Find the maximum distance between any two elements 
 * where one element is from one array and the other element is from another array. The distance between two elements is 
 * defined as `abs(A[i] - B[j])`, where `i` and `j` are indices in different arrays.
 * 
 * Intuition:
 * The goal is to find the maximum possible distance between the smallest element in one array and the largest element in 
 * another array. Since each array is already sorted, the smallest element will be the first element, and the largest will 
 * be the last. A naive approach involves sorting, while a more optimal approach uses linear traversal to track the minimum 
 * and maximum values.
 * 
 * Approach:
 * - **Sorting-Based Approach:** Sort the arrays based on the maximum and minimum values separately. Compare the smallest 
 *   element in the array with the second largest in another array and vice versa.
 * - **Linear-Time Approach:** Track the two smallest and two largest values along with their indices using min-heaps and 
 *   max-heaps. This approach avoids the need for sorting and reduces the time complexity.
 * 
 * Time Complexity:
 * - **Sorting-Based Approach:** The time complexity is `O(n log n)`, where `n` is the number of arrays.
 * - **Linear-Time Approach:** The time complexity is `O(n)`, as it only requires a single pass through the arrays and uses 
 *   heaps to track the necessary values.
 * 
 * Space Complexity:
 * - The space complexity is `O(1)` if we ignore the input and output, as the extra space used is constant.
 */

#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

class Solution {
public:
    /**
     * @brief Helper function to sort arrays based on their maximum element.
     * 
     * @param a The first array.
     * @param b The second array.
     * @return bool True if the max element of a is greater than that of b.
     */
    static bool sortMax(const vector<int> &a, const vector<int> &b) {
        int m = a.size() - 1, n = b.size() - 1;
        if (a[m] == b[n]) {
            return a[0] > b[0];
        }
        return a[m] > b[n];
    }
    
    /**
     * @brief Helper function to sort arrays based on their minimum element.
     * 
     * @param a The first array.
     * @param b The second array.
     * @return bool True if the min element of a is less than that of b.
     */
    static bool sortMin(const vector<int> &a, const vector<int> &b) {
        int m = a.size() - 1, n = b.size() - 1;
        if (a[0] == b[0]) {
            return a[m] < b[n];
        }
        return a[0] < b[0];
    }
    
    /**
     * @brief Sorting-based approach to find the maximum distance.
     * 
     * @param arrays The list of sorted arrays.
     * @return int The maximum distance.
     */
    int maxDistanceSortingBased(vector<vector<int>>& arrays) {
        sort(arrays.begin(), arrays.end(), sortMax);
        int max1 = arrays[0].back();
        int min1 = INT_MAX;
        
        for (int i = 1; i < arrays.size(); i++) {
            min1 = min(min1, arrays[i].front());
        }
        
        sort(arrays.begin(), arrays.end(), sortMin);
        int min2 = arrays[0].front();
        int max2 = INT_MIN;
        
        for (int i = 1; i < arrays.size(); i++) {
            max2 = max(max2, arrays[i].back());
        }
        
        return max(abs(max2 - min2), abs(max1 - min1));
    }
    
    /**
     * @brief Linear-time approach to find the maximum distance using heaps.
     * 
     * @param arrays The list of sorted arrays.
     * @return int The maximum distance.
     */
    int maxDistanceLinearTime(vector<vector<int>> &arrays) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        priority_queue<pair<int, int>> maxHeap;
        int m = arrays.size();
        
        for (int i = 0; i < m; i++) {
            int n = arrays[i].size();
            minHeap.push({arrays[i][n - 1], i});
            if (minHeap.size() > 2) {
                minHeap.pop();
            }
            
            maxHeap.push({arrays[i].front(), i});
            if (maxHeap.size() > 2) {
                maxHeap.pop();
            }
        }
        
        int min2 = maxHeap.top().first;
        maxHeap.pop();
        int min1 = maxHeap.top().first;

        int max2 = minHeap.top().first;
        minHeap.pop();
        int max1 = minHeap.top().first;
        
        if(maxHeap.top().second == minHeap.top().second) {
            return max(abs(max2 - min1), abs(max1 - min2));
        }
        
        return max1 - min1;
    }
    
    /**
     * @brief Main function to find the maximum distance in arrays.
     * 
     * @param arrays The list of sorted arrays.
     * @return int The maximum distance.
     */
    int maxDistance(vector<vector<int>> &arrays) {
        return maxDistanceLinearTime(arrays);
    }
};

