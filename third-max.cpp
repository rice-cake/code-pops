#include <iostream>
#include <vector>
#include <set>
using namespace std;

//rice-cake

/*
Problem 414 (Easy):

Given a non-empty array of integers, return the third maximum number in this array. 
If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1] Output: 1
Explanation: The third maximum is 1.

Example 2:
Input: [1, 2] Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:
Input: [2, 2, 3, 1] Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

*/

//Solution status: Accepted

class Solution {
public:
    //use set
    int set_thirdMax(vector<int>& nums) {
      set<int> maxs;  //asc
      set<int>::iterator sitr;
      maxs.insert(nums[0]); //nums is non-empty      
      for (int i = 1, n; i < nums.size(); ++i) {
        n = nums[i];
        sitr = maxs.find(n);
        if (sitr == maxs.end()) { //not seen n yet
          maxs.insert(n);
          if (maxs.size() > 3)
            maxs.erase(*maxs.begin()); //remove the smallest/last element          
        }
      }
      if (maxs.size() == 3)
        return *maxs.begin();  //smallest, value at front
      else
        return *maxs.rbegin(); //largest, value at back
    }

    /////////////////
    //returns index of smallest number amongst three distinct number
    int find_smallest(int *A, const int sz = 3) {      
      int a = (A[0] < A[1]) ? 0 : 1;
      return (A[a] < A[2]) ? a : 2;
    }

    //faster!
    int my_thirdMax(vector<int>& nums) {
      int maxs[3]; 
      int i = 0, n, j = 0;
      for ( ; i < nums.size() && j < 3; ++i) {
        n = nums[i];
        if (j == 0) {
          maxs[j] = n; ++j;
        }
        else if (j == 1) {  //ignore repeated elements
          if (n != maxs[0]) {
            maxs[j] = n; ++j;
          }
        }
        else if (j == 2) {
          if (n != maxs[0] && n != maxs[1]) {
            maxs[j] = n; ++j;
          }
        }
      }
      //if (j == 0) //nums is empty
      if (j == 1) //only one number
        return maxs[0];
      if (j == 2) //only two numbers
        return (maxs[0] > maxs[1] ? maxs[0] : maxs[1]);
      //j == 3, three or more numbers
      int k = find_smallest(maxs);      
      for ( ; i < nums.size(); ++i) {
        n = nums[i];  //check n not already in maxs
        if (n != maxs[0] && n != maxs[1] && n != maxs[2]) {
          if (n > maxs[k]) {
            maxs[k] = n;
            k = find_smallest(maxs);
          }
        }
      }
      return maxs[k];
    }

    /////////////////
    //fastest! inspired by a discussed solution, intuitive solution
    //sort maxs inplace as nums is traversed, insertion sort (desc)    
    int sel_thirdMax(vector<int>& nums) {
      int maxs[3]; 
      int i = 0, n, j = 0;  //j keeps track of how many elements are in maxs
      for ( ; i < nums.size() && j < 3; ++i) {
        n = nums[i];
        if (j == 0) {
          maxs[j] = n; ++j;
        }
        else if (j == 1) {  //already one element in maxs           
          if (n > maxs[0]) {
            maxs[j] = maxs[0];
            maxs[0] = n; ++j;
          }
          else if (n < maxs[0]) { //checks n not already in maxs
            maxs[j] = n; ++j;
          }
        }
        else if (j == 2) { //already two element in maxs          
          if (n > maxs[0]) {
            maxs[j] = maxs[1];  //move existing elements down one spot
            maxs[1] = maxs[0];
            maxs[0] = n; ++j;
          }
          else if (n != maxs[0] && n > maxs[1]) {
            maxs[j] = maxs[1];
            maxs[1] = n; ++j;
          }
          else if (n < maxs[1]) {
            maxs[j] = n; ++j;
          }
        }
      }            
      for ( ; i < nums.size(); ++i) {
        n = nums[i];  
        if (n > maxs[0]) {
          maxs[2] = maxs[1];
          maxs[1] = maxs[0];
          maxs[0] = n;
        }
        else if (n != maxs[0] && n > maxs[1]) {
          maxs[2] = maxs[1];
          maxs[1] = n;
        }
        else if (n != maxs[0] && n != maxs[1] && n > maxs[2]) {
          maxs[2] = n;
        }
      }
      if (j == 1 || j == 2) //no third max
        return maxs[0];
      else
        return maxs[2];
    }
};

//test driver

int main() {
  
  //auto nums_il = { 3, 2, 1 };   //1
  //auto nums_il = { 1, 2 };    //2
  //auto nums_il = { 1, 2, 1, 2 };    //2
  //auto nums_il = { 2, 2, 3, 1 }; //1 repeated elements, within 3
  //auto nums_il = { 2, 3, 5, 3, 7, 8 };  //5 repeated elements > 3
  //auto nums_il = { 4 };   //4
  //auto nums_il = { 6, 6 };  //6
  auto nums_il = { 1, 2, 2, 5, 3, 5 };  //2

  vector<int> nums_v(nums_il);

  Solution s;
  cout << s.sel_thirdMax(nums_v) << endl;
  
  char c; cin >> c;
  return 0;
}


