#include <iostream>
#include <string>
using namespace std;

//rice-cake

/*
Problem 859 (Easy): 

Given two strings A and B of lowercase letters, return true if and only if 
we can swap two letters in A so that the result equals B.
 
Example 1:
Input: A = "ab", B = "ba"
Output: true

Example 2:
Input: A = "ab", B = "ab"
Output: false

Example 3:
Input: A = "aa", B = "aa"
Output: true

Example 4:
Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true

Example 5:
Input: A = "", B = "aa"
Output: false

Note:

    0 <= A.length <= 20000
    0 <= B.length <= 20000
    A and B consist only of lowercase letters.
*/

//My solution (Accepted):

class Solution {
public:
    bool buddyStrings(string A, string B) {
      int sz = A.size();
      if (sz < 2 || B.size() != sz) //string needs to have at least 2 chars
        return false;
      int diff = 0; char p = '9', q = '9', x = '9', y = '9';
      int same = 0, j; char r = '9';
      for (int i = 0; i < sz; ++i) {
        if (A[i] != B[i]) {
          if (diff == 0) {
            p = A[i]; x = B[i];
          }
          else if (diff == 1) {
            q = A[i]; y = B[i];
          }
          ++diff;
          if (diff > 2)
            return false;
        }
        else {  // A[i] == B[i]
          r = A[i];
          j = A.find(r, i+1);
          if (same == 0 && j > 0 && B[j] == r)
            ++same; //only need one exchange between same char
        }
      }
      if (diff == 0) { //A == B
        return (same >= 1); 
      }
      else if (diff == 2) { //2 pairs are different
        return (p == y && q == x);
      }
      return false; // 1
    }
};

//test driver

int main() {

  Solution s;

  //True
  //string A = "aabaca", B = "aacaba"; 
  //string A = "bb", B = "bb";
  //string A = "abba", B = "baba";
  //string A = "abbb", B = "abbb";
  //string A = "abab", B = "abab";

  //False
  //string A = "", B = ""; 
  //string A = "aa", B = "";
  //string A = "h", B = "h";
  //string A = "ab", B = "ab";
  //string A = "aa", B = "cc";
  //string A = "aabb", B = "ccbb";
  //string A = "aacaaa", B = "aacdaa";  
  //string A = "aabcaa", B = "aacdaa";  
  string A = "aabcaaf", B = "aacbaae";    

  cout << s.buddyStrings(A, B) << endl;

  char c; cin >> c;
  return 0;
}


