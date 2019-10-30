# -*- coding: utf-8 -*-
"""
Created on Tue Oct 29 16:30:55 2019

@author: rice-cake

Problem 20 (Easy):

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

Example 3:

Input: "(]"
Output: false

Example 4:

Input: "([)]"
Output: false

Example 5:

Input: "{[]}"
Output: true

"""

# My solutions (Accepted)

# Second Approach (Accepted without the re portion)
# at least number of lefts must equal number of rights
# use stack LIFO to check arrangement and type

import re
class Solution2:
    L = ['(', '{', '[']
    R = [')', '}', ']']
    
    def isValid(self, s: str) -> bool: 
        if len(re.findall('[\[\(\{]', s)) != len(re.findall('[\}\)\]]', s)):
            # print('len mismatch') # to check this is the path used
            return False
        # print('lens match')
        stack = []
        for e in s:            
            if e in self.L:
                stack.append(e) # push onto the stack
            elif e in self.R:
                try:
                    b = stack.pop() # pop the last element
                except IndexError: # pop from empty list
                    return False # right without left
                if self.L.index(b) != self.R.index(e): # left and right match
                    return False
        return len(stack) == 0
    

# First Approach (Accepted)
# practise exceptions, O-O prog
        
class Solution:
    L = ['(', '{', '[']    
    def is_left(self, c: chr) -> int:
        """ returns index into L if c in L, -1 o.w. """
        try:
            return self.L.index(c)    
        except ValueError:
            return -1

    R = [')', '}', ']']
    def is_right(self, c: chr) -> int:
        """ returns index into R if c in R, -1 o.w. """
        try:
            return self.R.index(c)    
        except ValueError:
            return -1        

    def isValid(self, s: str) -> bool:        
        b = list(s) # str immutable
        for i in range(len(b)):
            r = self.is_right(self, b[i]) 
            # r = self.is_right(b[i]) 
            if r != -1:
                j = i-1
                while j >= 0 and b[j] is None:
                    j -= 1
                if j < 0:
                    return False  # right without left
                else:
                    l = self.is_left(self, b[j])
                    # l = self.is_left(b[j])
                    if r != l:                        
                        return False # right doesn't match left
                    else: # right matches left
                        b[i] = None
                        b[j] = None
        
        if len([ False for e in b if e != None ]) == 0:
            return True
        else:
            return False


# test driver
        
sol = Solution

input = "()[{}"
print(sol.isValid(sol, input)) # False
input = "()[]{}"
print(sol.isValid(sol, input)) # True
input = "{[]}"
print(sol.isValid(sol, input)) # True
input = "{[)}"
print(sol.isValid(sol, input)) # False
input = ""
print(sol.isValid(sol, input)) # True
input = "{}([)]"
print(sol.isValid(sol, input)) # False
input = '['
print(sol.isValid(sol, input)) # False
input = ')'
print(sol.isValid(sol, input)) # False
input = '((())){{[]}}'
print(sol.isValid(sol, input)) # True


