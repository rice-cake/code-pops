#include <iostream>
#include <vector>
#include <map>
using namespace std;

//rice-cake

/*
Problem 703 (Easy): 

Design a class to find the kth largest element in a stream. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k 
and an integer array nums, which contains initial elements from the stream. 

For each call to the method KthLargest.add, 
return the element representing the kth largest element in the stream.

Example:

int k = 3; int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);

kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8

Note:
You may assume that nums' length >= k-1 and k >= 1.

*/

//My solution:

class KthLargest {
  public:
    KthLargest(int k, vector<int>& nums) {
      this->k = k; c = 0;
      if (nums.empty()) { m = INT_MIN; return; }
      m = nums[0]; 
      n_counts.clear(); 
      for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr) {
        int n = *itr;
        if (c < k) {  //have not seen at least k elements yet
          mitr = n_counts.find(n);  //add n to map
          if (mitr != n_counts.end())
            mitr->second += 1;
          else {
            n_counts.insert(pair<int, int>(n, 1));
            if (n < m) m = n; 
          }
          ++c;
        }
        else
          add(n);
      }
    }
    
    int add(int val) {      
      if (c < k) {  //have not seen at least k elements yet
        mitr = n_counts.find(val);  //add val to map
        if (mitr != n_counts.end())
          mitr->second += 1;
        else {
          n_counts.insert(pair<int, int>(val, 1));
          if (m == INT_MIN || val < m) //in case start with empty n_counts
            m = val;          
        }
        ++c;
      }
      else { //map already knows about k elements, c == k
        //if (val <= m) continue; //map only needs to know about k largest elements
        if (val > m) {
          mitr = n_counts.find(val); 
          if (mitr != n_counts.end())
            mitr->second += 1;
          else
            n_counts.insert(pair<int, int>(val, 1));
          if (n_counts.begin()->second == 1) {  //only one smallest element
            n_counts.erase(n_counts.begin()->first);
            m = n_counts.begin()->first;  //replace m with new smallest element
          }
          else //decrement count of smallest element
            n_counts.begin()->second -= 1;            
        }
      }
      return m;
    }

  private:
    int k, m; //m is smallest element (kth largest)
    int c;  //c is sum of n_counts->second
    map<int, int> n_counts;
    map<int, int>::iterator mitr;            
};



/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

        

//test driver

int main() {
  int k;
  
  /* auto nums_il = { 2, 2 }; k = 2;
  cout << obj->add(3) << endl;  //2
  cout << obj->add(1) << endl;  //2 */
  
  /* //return the smallest of the largest if nums have fewer than k elements
  auto nums_il = { 2, 3, 5, 3 }; k = 6;
  cout << obj->add(7) << endl;  //2
  cout << obj->add(8) << endl;  //2 */
  
  /* auto nums_il = { 1, 2 }; k = 3;
  cout << obj->add(2) << endl;  //1
  cout << obj->add(5) << endl;  //2
  cout << obj->add(3) << endl;  //2
  cout << obj->add(5) << endl;  //3 */
  
  /* auto nums_il = { 3, 2, 1 }; k = 2;
  cout << obj->add(5) << endl;  //3
  cout << obj->add(6) << endl;  //5
  cout << obj->add(4) << endl;  //5 */  
   
  /* auto nums_il = { 4, 5, 8, 2 }; k = 3;
  cout << obj->add(3) << endl;  //4
  cout << obj->add(5) << endl;  //5
  cout << obj->add(10) << endl; //5
  cout << obj->add(9) << endl;  //8
  cout << obj->add(4) << endl;  //8 */

  /* auto nums_il = { 3, 2, 3 }; k = 4;
  cout << obj->add(1) << endl;  //1
  cout << obj->add(2) << endl;  //2
  cout << obj->add(4) << endl;  //2
  cout << obj->add(5) << endl;  //3
  cout << obj->add(5) << endl;  //3
  cout << obj->add(6) << endl;  //4 */

  /* auto nums_il = { 4 }; k = 1;  
  cout << obj->add(NULL) << endl; //4 */

  /* auto nums_il = { 6, 6 }; k = 2;
  cout << obj->add(NULL) << endl; //6 */

  //vector<int> nums_v(nums_il);

  /* vector<int> nums_v; k = 1;
  cout << obj->add(-3) << endl;  //-3
  cout << obj->add(-2) << endl;  //-2
  cout << obj->add(-4) << endl;  //-2
  cout << obj->add(0) << endl;    //0
  cout << obj->add(3) << endl;    //3 */
  
  vector<int> nums_v; k = 1;
  /* cout << obj->add(nullptr) << endl;  //NULL, 0
  cout << obj->add(-3) << endl;  //-3, 0
  cout << obj->add(-2) << endl;  //-2, 0
  cout << obj->add(-4) << endl;  //-2, 0
  cout << obj->add(0) << endl;    //0, 0
  cout << obj->add(4) << endl;    //4, 4
  cout << obj->add(NULL) << endl;  //4, 4 */

  KthLargest* obj = new KthLargest(k, nums_v);
  cout << obj->add(NULL) << endl;  //NULL, 0
  cout << obj->add(-3) << endl;  //-3, 0
  cout << obj->add(-2) << endl;  //-2, 0
  cout << obj->add(-4) << endl;  //-2, 0
  cout << obj->add(0) << endl;    //0, 0
  cout << obj->add(4) << endl;    //4, 4
  cout << obj->add(NULL) << endl;  //4, 4 
  
  //cout << (0 == NULL) << endl; //1 True
  //cout << INT_MIN << " " << INT_MAX << endl;

  char c; cin >> c;
  return 0;
}



