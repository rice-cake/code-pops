# -*- coding: utf-8 -*-
"""
Created on Tue Oct 29 12:07:59 2019

@author: rice-cake

Problem 14 (Easy):

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: ["dog","racecar","car"]
Output: ""

Explanation: There is no common prefix among the input strings.

Note:

All given inputs are in lowercase letters a-z.

"""
# My solution (Accepted)

class Solution:
    def longestCommonPrefix(self, strs: list) -> str:
        """
        Approach: "stack" the strings, and examine them column-wise,
        stop when letters in a column are not identical.
        n: order of the number of strings
        loop: order of the length of the shortest string, and n
        More efficient not to use set, can stop once a different
        letter is found.
        """
        if len(strs) < 1:
            return ""
        n = min([len(s) for s in strs]) # length of the shortest string
        for i in range(n):                        
#            if len(set([s[i] for s in strs])) > 1:
#                return strs[0][:i]
            c = strs[0][i]
            for s in strs[1:]:
                if s[i] != c:
                    return strs[0][:i]
        return strs[0][:n] # return the shortest string


        
# test driver
            
sol = Solution

input = ["flower","flow","flight"]
print(sol.longestCommonPrefix(sol, input))

input = ["dog","racecar","car"]
print(sol.longestCommonPrefix(sol, input))

input = []
print(sol.longestCommonPrefix(sol, input))

input = ["flow","flow","flow"]
print(sol.longestCommonPrefix(sol, input))

input = ["end", "ends", "ending"]
print(sol.longestCommonPrefix(sol, input))

input = ["aa", "a"]
print(sol.longestCommonPrefix(sol, input))

        