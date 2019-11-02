#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

//rice-cake

/*
Problem 665 (Easy):

Given an array with n integers, your task is to check if it could become non-decreasing(monotonically increasing) by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds 
for every i (1 <= i < n).

Example 1:

Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:

Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.

Note: The n belongs to [1, 10,000].   
*/

//My solution (Accepted):

class Solution {
public:    
  bool checkPossibility(vector<int>& nums) {
    //loops through nums one to find the monotonically increasing subsequences
    int sz = nums.size();
    int q = 1, j;
    for (int i = 0; i < sz - 1; ++i) {
      if (nums[i] > nums[i + 1]) { //start a new subsequence          
        j = i; ++q;
      }
    }
    if (q == 1)
      return true;
    else if (q > 2)
      return false;
    else {  //q == 2, modified from below after peeking at a posted solution
      if (j == 0 || j == sz - 2)  //change either first or last element
        return true;
      else { //subsequences have more than one element
        if (nums[j] <= nums[j + 2] || nums[j - 1] <= nums[j + 1])
          return true;        
      }
    }
    return false;
  }    

  /* int first_back = nums[j], changes_in_second = 0;
      for (int i = j + 1; i < sz; ++i) {
        if (nums[i] < first_back)
          ++changes_in_second;
      }
      if (changes_in_second <= 1)
        return true;
      int second_front = nums[j+1], changes_in_first = 0;
      for (int i = 0; i < j+1; ++i) {
        if (nums[i] > second_front)
          ++changes_in_first;
      }
      if (changes_in_first <= 1)
        return true;
      return false;
    } */
  /* when q == 2: for two monotonically increasing subsequences to be 
  a monotonically increasing subsequence, either elements of the second subsequence 
  need to be > last element of the first subsequence, or elements in the first subsequence 
  need to be < the first lement of the second subsquence */ 
};


//test driver

int main() {

  Solution s;
  ostream_iterator<int> os_itr(cout, " ");

  //True (1)
  //auto nums_il = { -3, -2, -1 };  //nothing to change
  //auto nums_il = { 0 };
  //auto nums_il = { -3, -2, -1, 2, 3, 5 };
  //auto nums_il = { 4, 2, 3, 3 };  //change one, first
  //auto nums_il = { 1, 2, 4, 2, 3, 3 }; //change one, first
  //auto nums_il = { 3, 5, 2 };   //change one, second
  auto nums_il = { 2, 3, 5, 3, 7, 8 };  //change one, second
  
  //False (0)    
  //auto nums_il = { 2, 3, 2, 4, 2 }; //q > 2
  //auto nums_il = { 4, 2, 1 };  
  //auto nums_il = { 2, 3, 5, -3, -2, -1 };  //q == 2, too many to change in second or first
  
  vector<int> nums_v(nums_il);  
  cout << s.checkPossibility(nums_v) << endl;
  
  copy(nums_v.begin(), nums_v.end(), os_itr); cout << endl;

  char c; cin >> c;
  return 0;
}

