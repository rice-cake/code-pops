#include <iostream>
using namespace std;

//rice-cake

/*
Problem 121 (Easy): 

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell 
one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:
Input: [7,1,5,3,6,4] Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:
Input: [7,6,4,3,1] Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

//My solution (Accepted):

//C style
int maxProfit1(int* prices, int pricesSize) {
  //assumes all positive ints
  if (pricesSize < 1) return 0;
  int max_profit = 0, profit = 0;  
  int i = 1, j = 0, max_p = prices[0], p; //max_p is max price for a block
  int min_p = prices[0], q; //min_p is min over prices (from start) to before max_p
  while (i < pricesSize) {    
    p = prices[i]; 
    if (p >= max_p)
      max_p = p;    
    else {      
      while (j < i) {
        q = prices[j];
        if (q < min_p)
          min_p = q;
        ++j;
      }
      profit = max_p - min_p;
      if (profit > max_profit) {
        max_profit = profit;
        //printf("%d %d %d \n", i, j, max_profit);
      }
      max_p = p; //start new block
    }
    ++i;
  }  
  while (j < i) { //process the last block
    q = prices[j];
    if (q < min_p)
      min_p = q;
    ++j;
  }
  profit = max_p - min_p;
  if (profit > max_profit)
    max_profit = profit;

  return max_profit;
}


int maxProfit(int* prices, int pricesSize) {
  //assumes all positive ints, O(n)
  if (pricesSize < 1) return 0;
  int max_profit = 0, profit = 0;  
  int i = 1, max_p = prices[0], p; //max_p is max price for a block
  int min_p = prices[0], q; //min_p is min over prices (from start) to before max_p
  while (i < pricesSize) {    
    p = prices[i]; 
    if (p >= max_p)
      max_p = p;    
    else {
      profit = max_p - min_p;
      if (profit > max_profit) {
        max_profit = profit;
        //printf("%d %d %d \n", min_p, max_p, max_profit);
      }
      max_p = p; //start new block, update max_p after
      if (p < min_p)  //update min_p after, so profit is buy before sell
        min_p = p;
    }
    ++i;
  }
  profit = max_p - min_p;   //process the last block
  if (profit > max_profit)
    max_profit = profit;

  return max_profit;
}


//cleaner (but slower?), from solution in discussion
int sol_maxProfit(int* prices, int pricesSize) {
  //assumes all positive ints, O(n)
  if (pricesSize < 1) return 0;
  int max_profit = 0, min_p = prices[0];  
  int i = 1, p;  
  while (i < pricesSize) { 
    p = prices[i];
    if (p < min_p)
      min_p = p;    
    if (p - min_p > max_profit)
      max_profit = p - min_p;
    ++i;
  }
  return max_profit;
}


//test driver

int main() {
  int n;
  //int prices[6] = { 7, 1, 5, 3, 6, 4 }; n = 6;  //5
  //int prices[5] = { 7, 6, 4, 3, 1 }; n = 5; //0  
  //int prices[6] = { 3, 7, 5, 1, 4, 6 }; n = 6; //5
  //int prices[6] = { 1, 3, 5, 5, 6, 10 }; n = 6; // 9
  int prices[9] = { 2, 3, 5, 5, 1, 10, 4, 3, 12 }; n = 9; // 11
  
  cout << maxProfit(prices, n) << endl;
  
  char c; cin >> c;
  return 0;
}


