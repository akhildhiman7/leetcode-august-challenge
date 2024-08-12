/**
 * @file Day 12 Kth Largest Element in a Stream.cpp
 * @brief Solution to the LeetCode problem "Kth Largest Element in a Stream"
 * @link https://leetcode.com/problems/kth-largest-element-in-a-stream/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Design a class that finds the `k`-th largest element in a stream of numbers. The class should maintain a stream of integers and provide a function to return the `k`-th largest element whenever a new number is added.
 * 
 * Intuition:
 * The problem can be efficiently solved using a min-heap. The idea is to maintain a heap that contains exactly `k` largest elements seen so far. The root of this heap will always be the `k`-th largest element.
 * 
 * Approach:
 * - **Constructor:** Initialize the object with a `k` value and a list of integers `nums`. Insert all elements from `nums` into a max-heap, then transfer exactly `k` elements from the max-heap to a min-heap.
 * - **Add Function:** When a new value is added, if the size of the min-heap is less than `k`, simply add the new value. Otherwise, compare the new value with the smallest element in the min-heap (the `k`-th largest element). If the new value is larger, replace the smallest element in the min-heap with the new value. The root of the min-heap is always the `k`-th largest element.
 * 
 * Time Complexity:
 * - The time complexity for the `add` function is `O(log k)` because insertion and deletion in a heap take logarithmic time relative to the number of elements.
 * 
 * Space Complexity:
 * - The space complexity is `O(k)` because the size of the min-heap is maintained at `k`.
 */

#include <queue>
#include <vector>

class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::priority_queue<int> maxHeap;
    int k;

    /**
     * @brief Constructor to initialize the KthLargest object.
     * 
     * @param k The order of the largest element to maintain.
     * @param nums The initial list of numbers.
     */
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        for (auto &i: nums) {
            maxHeap.push(i);
        }
        
        while (!maxHeap.empty() && k--) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    /**
     * @brief Add a new number to the stream and return the k-th largest element.
     * 
     * @param val The new number to add.
     * @return int The k-th largest element after the addition.
     */
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
            return minHeap.top();
        }
        
        if (val <= minHeap.top()) {
            return minHeap.top();
        }

        minHeap.push(val);
        minHeap.pop();
        
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

