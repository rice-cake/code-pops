#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

//rice-cake

/*
Problem 27 (Easy):

Given an array nums and a value val, remove all instances of that value in-place and 
return the new length.
Do not allocate extra space for another array, 
you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. 
It doesn't matter what you leave beyond the new length.

Example 1:
Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,1,2,2,3,0,4,2], val = 2,
Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.

Note that the order of those five elements can be arbitrary.
It doesn't matter what values are set beyond the returned length.
*/

//Solution status: Accepted

class Solution {
public:
    int my_removeElement(vector<int>& nums, int val) {
      int sz = nums.size();
      //start from the end of the vector
      int i = sz - 1, j = sz - 1;   //j gets updated only when nums[i] == val
      while(i >= 0 && nums[i] == val) { //trailing vals, or all vals
        --j; --i;
      }
      while(i >= 0) {  
        if (nums[i] == val) { //swap with the last non-val element
          nums[i] = nums[j];
          --j;  //keep track of last non-val element in nums
        }
        --i;
      }
      return j+1;
    }

    //a solution from the Discussion section, requires <algorithm>
    int removeElement(vector<int>& nums, int val) {
      return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
    }
};


//test driver

int main() {
  
  Solution s;  
  ostream_iterator<int> os_itr(cout, " ");
  
  int val = 3; auto nums_il = { 3, 2, 2, 3 }; 
  //int val = 2; auto nums_il = { 0, 1, 2, 2, 3, 0, 4, 2 };
  //int val = 3; auto nums_il = { 3, 3, 3, 3 };   //all vals
  //int val = 2; auto nums_il = { 3, 3, 3, 3 }; //no vals
  //int val = 2; auto nums_il = { 2, 3, 3, 3 }; //first val
  //int val = 3; auto nums_il = { 2, 3, 3, 3 }; //first non-val
  //int val = 2; auto nums_il = { 3, 3, 3, 2 };   //last val
  //int val = 3; auto nums_il = { 3, 3, 3, 2 };   //last non-val

  vector<int> nums_v(nums_il);  
      
  copy(nums_v.begin(), nums_v.end(), os_itr); 
  cout << ", " << val << endl;

  cout << s.my_removeElement(nums_v, val) << ", ";
  copy(nums_v.begin(), nums_v.end(), os_itr); cout << endl;

  char c; cin >> c;
  return 0;
}

