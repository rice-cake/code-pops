#include <iostream>
#include <vector>
// #include <initializer_list>
using namespace std;

//rice-cake

/*
Problem (Easy):
Given an array of integers, return indices of the two numbers such that 
they add up to a specific target. 
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9, return [0, 1].
*/

//Solution status: Accepted

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int sz = nums.size();
        for (int i =0; i < sz-1; ++i) {
            for (int j = i+1; j < sz; ++j) {
                if (nums.at(i) + nums.at(j) == target) {
                    res.at(0) = i; res.at(1) = j;
                    return res;
                }
            }
        }        
        return res; 
    }
};

int main() {
  int target = 9;
  auto nums_il = { 2, 7, 11, 15 };     
  vector<int> nums_v(nums_il);  
  Solution s;
  vector<int> res_v = s.twoSum(nums_v, target);
  cout << res_v[0] << " " << res_v[1] << endl;  
  char c; cin >> c;
  return 0;
}
