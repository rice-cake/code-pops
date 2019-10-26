# -*- coding: utf-8 -*-
"""
Created on Fri Oct 25 23:09:05 2019

@author: rice-cake

Problem 13 (Easy):

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, 
XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four 
is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it 
making four. The same principle applies to the number nine, which is written as IX. There are six 
instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 
3999.

Example 1: Input: "III" Output: 3

Example 2: Input: "IV" Output: 4

Example 3: Input: "IX" Output: 9

Example 4: Input: "LVIII" Output: 58  Explanation: L = 50, V= 5, III = 3.

Example 5: Input: "MCMXCIV" Output: 1994 Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

"""
# My solution (Accepted)

class Solution:
 
    def __init__(self):
        pass
    
    rom_val_d = { 'I':1, 'V':5, 'X':10, 'L':50, 
                 'C':100, 'D':500, 'M':1000 }
    
    def romanToInt(self, s: str) -> int:        
        # translate and check whether s is a valid roman string
        res, prev_v = 0, 0        
        for r in s:
            if r not in self.rom_val_d: # check valid key, symbol
                res = 0
                print('Invalid roman string')
                break;
            v = self.rom_val_d[r]
            if 0 == res or v <= prev_v:
                res += v                
            elif (1 == prev_v and (5 == v or 10 == v)) or \
                 (10 == prev_v and (50 == v or 100 == v)) or \
                 (100 == prev_v and (500 == v or 1000 == v)) :
                     res = res - (2 * prev_v) + v
            else:
                res = 0
                print('Invalid roman string')
                break;
            prev_v = v
            # print(r, prev_v, res)
        return res


# driver/test code
        
sol = Solution

print(sol.romanToInt(sol, 'XCIV'))

print(sol.romanToInt(sol, 'MCMXCIV'))

print(sol.romanToInt(sol, 'MLCMXCIV'))

print(sol.romanToInt(sol, 'II1'))





