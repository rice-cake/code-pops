#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//rice-cake

/*
Problem 215 (Medium): 

Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, 
not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2 Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4 Output: 4

Note:
You may assume k is always valid, 1 = k = array's length.

*/

//My solution (Accepted):

class Solution {
public:
    //uses map
    int map_findKthLargest(vector<int>& nums, int k) {
      map<int, int> n_counts;
      map<int, int>::iterator mitr;
      int n;
      for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr) {
        n = *itr;
        mitr = n_counts.find(n);
        if (mitr != n_counts.end())
          mitr->second += 1;
        else
          n_counts.insert(pair<int, int>(n, 1));
      }
      for (map<int, int>::reverse_iterator rmitr = n_counts.rbegin();
        rmitr != n_counts.rend() && k > 0; ++rmitr) {
        n = rmitr->first;
        k = k - rmitr->second;
      }
      return n;
    }   

    //just a little faster than above
    //don't have to store all n's and their counts, once k is reached!
    //keep track of the smallest n for k
    //don't have to iterate in reverse, the answer is m!
    int findKthLargest(vector<int>& nums, int k) {
      map<int, int> n_counts;
      map<int, int>::iterator mitr;
      int n, m = nums[0], c=0;  //m is smallest element (kth largest)
      for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr) {
        n = *itr;
        if (c < k) {  //have not seen at least k elements yet
          mitr = n_counts.find(n);  //add n to map
          if (mitr != n_counts.end())
            mitr->second += 1;
          else
            n_counts.insert(pair<int, int>(n, 1));          
          if (n < m) m = n; ++c;
        }
        else {  //map already knows about k elements, c == k
          //if (n <= m) continue; //map only needs to know about k largest elements
          if (n > m) {
            mitr = n_counts.find(n); 
            if (mitr != n_counts.end())
              mitr->second += 1;
            else
              n_counts.insert(pair<int, int>(n, 1));
            if (n_counts.begin()->second == 1) {  //only one smallest element
              n_counts.erase(n_counts.begin()->first);
              m = n_counts.begin()->first;  //replace m with new smallest element
            }
            else //decrement count of smallest element
              n_counts.begin()->second -= 1;  
          }
        }
      }
      return m;
    }

    //uses algorithm, 2x faster than above
    int sort_findKthLargest(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      return *(nums.rbegin() + k - 1);
    }
};


//test driver

int main() {
  int k;
  
  //auto nums_il = { 2, 2, 3, 1 }; k = 2; //2  
  //auto nums_il = { 2, 3, 5, 3, 7, 8 }; k = 6;  //2  
  //auto nums_il = { 4 }; k = 1;  //4  
  //auto nums_il = { 6, 6 }; k = 2; //6    
  //auto nums_il = { 1, 2, 2, 5, 3, 5 }; k = 3; //3
  //auto nums_il = { 3, 2, 1, 5, 6, 4 }; k = 2; // 5
  auto nums_il = { 3, 2, 3, 1, 2, 4, 5, 5, 6 }; k = 4; // 4
  
  vector<int> nums_v(nums_il);
  Solution s;  
  //cout << s.sort_findKthLargest(nums_v, k) << endl;
  cout << s.findKthLargest(nums_v, k) << endl;

  char c; cin >> c;
  return 0;
}



