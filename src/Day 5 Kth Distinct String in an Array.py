"""
@file Day 5 Kth Distinct String in an Array.py
@brief Solution to the LeetCode problem "Kth Distinct String in an Array"
@link https://leetcode.com/problems/kth-distinct-string-in-an-array/
 
Algorithm Explanation:
 
Problem Statement:
Given an array of strings arr, and an integer k, return the kth distinct string in the array.
The distinct strings are the strings that appear only once in the array.
If there are fewer than k distinct strings, return an empty string "".
 
To solve this problem, we can use the following approach:
1. Use a dictionary to count the frequency of each string in the array.
2. Iterate through the array and check the frequency of each string.
3. If the frequency of a string is 1, it is a distinct string.
4. Keep track of the number of distinct strings found.
5. Return the kth distinct string if found, otherwise return an empty string.
 
The time complexity of this approach is O(n), where n is the length of the array.
"""
 
from typing import List
from collections import defaultdict
 
class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        # Count the frequency of each string in the array
        dic = defaultdict(int)
        for s in arr:
            dic[s] += 1
        
        # Iterate through the array to find the kth distinct string
        for s in arr:
            if dic[s] == 1:
                if k == 1:
                    return s
                k -= 1
        
        # If there are fewer than k distinct strings, return an empty string
        return ""

