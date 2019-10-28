#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//rice-cake

/*
Problem 67 (Easy):

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

*/

//Solution status: Accepted

class Solution {
public:
    string addBinary(string a, string b) {
      /* no conversion to int (size limitation), no (explicit) bit operations
      processes the strings in reverse order, modifies the longer string 
      loop: order of the length of the longer string 
      */

      //if (a.empty()) return b;  //check not necessary, handled below
      //if (b.empty()) return a;  //for efficiency, clarity
      reverse(a.begin(), a.end()); 
      reverse(b.begin(), b.end()); 
      int a_sz = a.length(), b_sz = b.length();
      string accum = "", to_add = "";
      int accum_sz = 0, add_sz = 0;
      if (a_sz >= b_sz) {
        accum = a; accum_sz = a_sz;
        to_add = b; add_sz = b_sz;
      }
      else {
        accum = b; accum_sz = b_sz;
        to_add = a; add_sz = a_sz;
      }      
      char x, y, z = '0'; int i = 0;
      for (; i < add_sz; ++i) { 
        y = to_add[i];
        if (y == '0' && z == '0') continue; //no change to accum[i]
        x = accum[i];
        if (x == '0') {
          if (y == '1' && z == '0')
            accum[i] = '1';
          else if (y == '1' && z == '1') 
            accum[i] = '0';
          else if (y == '0' && z == '1') {
            accum[i] = '1'; z = '0';
          }
        }          
        else { //x == '1'
          if (y == '1' && z == '0') {
            accum[i] = '0'; z = '1';
          }
          else if (y == '1' && z == '1') 
            accum[i] = '1';
          else if (y == '0' && z == '1')
            accum[i] = '0';
        }
      }
      //if z == '0', we're done
      for (; i < accum_sz && z == '1'; ++i) { 
        if (accum[i] == '1') 
          accum[i] = '0';
        else if (accum[i] == '0') {
          accum[i] = '1'; z = '0';
        }
      }
      if (z == '1')
        accum.push_back('1');
      reverse(accum.begin(), accum.end());      
      return accum;
    }
};


//test driver

int main() {
  
  Solution s;  
  cout << s.addBinary("11", "1") << " 100" << endl; 
  cout << s.addBinary("11", "11") << " 110" << endl;  
  cout << s.addBinary("11", "1011") << " 1110" << endl;  
  cout << s.addBinary("1010", "1011") << " 10101" << endl;
  cout << s.addBinary("11100", "1011101111") << " 1100001011" << endl;
  cout << s.addBinary("", "1") << " 1" << endl; 
  cout << s.addBinary("", "") << "empty" << endl; 

  char c; cin >> c;
  return 0;
}

