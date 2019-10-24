#include <iostream>
#include <vector>
#include <string>
using namespace std;

//rice-cake

/*
Problem (Easy):

Determine whether an integer is a palindrome. An integer is a palindrome when it reads 
the same backward as forward.

Example 1: Input: 121 Output: true

Example 2: Input: -121 Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. 
Therefore it is not a palindrome.

Example 3: Input: 10 Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up: Coud you solve it without converting the integer to a string?
*/

//Solution status: Accepted

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector<short> v, rv;        
        while (x > 0) {
            v.push_back(x % 10);            
            x = x / 10;
        }
        rv = v;
        reverse(rv.begin(), rv.end());
        return(v == rv);
    }
};

int main() {
  string res[2] = { "false", "true" };
  Solution s;
  cout << res[s.isPalindrome(121)] << endl;  
  cout << res[s.isPalindrome(-121)] << endl;  
  cout << res[s.isPalindrome(10)] << endl;  

  char c; cin >> c;
  return 0;
}

