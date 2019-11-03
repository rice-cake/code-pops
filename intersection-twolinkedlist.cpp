#include <iostream>
#include <new>
#include <assert.h>
#include <set>
using namespace std;

//rice-cake

/*
Problem 160 (Easy):

Write a program to find the node at which the intersection of 
two singly linked lists begins. 

Example 1:

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], 
skipA = 2, skipB = 3

Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A. There are 3 nodes before the intersected node in B.

Example 2:

Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A. 
There are 1 node before the intersected node in B.

Example 3:

Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.
*/


// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


//Solution status: Accepted

class Solution {
public:  
    //for testing
    ListNode *create_joinedlist(int* a, int sz_a, ListNode* headC = NULL) {
      if (sz_a == 0)
        return headC; //maybe NULL
      int count = 0;
      ListNode* head = new ListNode(a[0]); ++count;
      ListNode* prev = head;
      for (int i = 1; i < sz_a; ++i) {
        ListNode* fresh = new ListNode(a[i]); ++count;
        prev->next = fresh;        
        prev = fresh;
      } 
      prev->next = headC; //maybe NULL
      //printf("%s %d \n", "allocated ", count);
      return head;      
    }

    void print_list(ListNode *head) {
      if (head == NULL) {
        cout << "empty list" << endl;
        return;
      }
      struct ListNode* ptr = head;
      cout << ptr->val;
      while (ptr->next != NULL) {
        ptr = ptr->next;
        cout << " -> " << ptr->val;
      }
      cout << endl;
    }
    
    //find (first) merge point (if any) of two lists, return ref to first common node     
    ListNode *my_getIntersectionNode(ListNode *headA, ListNode *headB) {
      if (headA == NULL || headB == NULL) {
        cout << "empty list" << endl;
        return NULL;
      }
      set<struct ListNode*> A_ptrs;
      set<struct ListNode*>::iterator sitr;
      struct ListNode* ptr = headA;
      while(ptr != NULL) {
        A_ptrs.insert(ptr);
        ptr = ptr->next;
      }
      ptr = headB;
      while (ptr != NULL) {
        sitr = A_ptrs.find(ptr);
        if (sitr != A_ptrs.end()) {
          assert((*sitr)->val == ptr->val);
          //cout << ptr->val << endl;
          return ptr;
        }
        ptr = ptr->next;
      } 
      return NULL;
    }

    //Approach 3 of suggested solution
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if (headA == NULL || headB == NULL) {
        cout << "empty list" << endl;
        return NULL;
      }
      struct ListNode* ptrA = headA; bool redirected_A = false;
      struct ListNode* ptrB = headB; bool redirected_B = false;
      int countA = 0, countB = 0;
      while (true) {
        if (ptrA == ptrB)
          return ptrA;
        if (ptrA != NULL) {
          ++countA;
          ptrA = ptrA->next;
        }
        else {
          printf("%s %d \n", "end of list A ", countA); 
          if (!redirected_A) {
            ptrA = headB; //redirecting to headB
            redirected_A = true;  //prevent endless redirection!
          }
          else
            return NULL;
        }
        if (ptrB != NULL) {
          ++countB;
          ptrB = ptrB->next;
        }
        else {
          printf("%s %d \n", "end of list B ", countB);
          if (!redirected_B) {
            ptrB = headA; //redirecting to headA
            redirected_B = true;
          }
          else
            return NULL;
        }
      }
    }
};


//test driver

int main() {
  //Input:  
  //to create empty list, assign sz = 0
  //c is common sublist to both a and b

  /* int sz_c = 0, sz_a = 0, sz_b = 1; //empty list
  int c[] = {5};
  int a[] = {2, 6, 4};
  int b[] = {1}; */

  /* int sz_c = 5, sz_a = 0, sz_b = 0; //join head, same list
  int c[] = {5, 4, 3, 3, 2};
  int a[] = {2, 6, 4};
  int b[] = {1}; */

  /* //[4,1,8,4,5], [5,0,1,8,4,5], //join middle
  int sz_c = 3, sz_a = 2, sz_b = 3; 
  int c[] = {8, 4, 5};
  int a[] = {4, 1};
  int b[] = {5, 0, 1}; */
  
  /* //[0,9,1,2,4], [3,2,4] //join last
  int sz_c = 2, sz_a = 3, sz_b = 1; 
  int c[] = {2, 4};
  int a[] = {0, 9, 1};
  int b[] = {3}; */

  /* //[2,6,4], [1,5] //no join
  int sz_c = 0, sz_a = 3, sz_b = 2; 
  int c[] = {0};
  int a[] = {2, 6, 4};
  int b[] = {1, 5}; */

  //[1,2,3,4,5,6,7,8], [1,8], //len A > 2x len B
  int sz_c = 1, sz_a = 7, sz_b = 1; 
  int c[] = {8};
  int a[] = {1, 2, 3, 4, 5, 6, 7};
  int b[] = {1};
  
  /////////////////////////////////////////////////////////
  Solution s;
  ListNode* headC = s.create_joinedlist(c, sz_c); 
  s.print_list(headC);

  ListNode* headA = s.create_joinedlist(a, sz_a, headC); 
  s.print_list(headA);

  ListNode* headB = s.create_joinedlist(b, sz_b, headC); 
  s.print_list(headB);

  ListNode* intersect_node = s.getIntersectionNode(headA, headB);
  assert(intersect_node == headC);
  s.print_list(intersect_node); 

  //delete allocated memory !
  int count = 0;
  ListNode* ptr; 
  if (sz_a > 0) {   
    while (headA->next != headC) { //maybe NULL
      ptr = headA;
      headA = headA->next;
      delete ptr;
      ++count;
    }
    delete headA; ++count;
  }
  //printf("%s %d \n", "deallocated ", count);
  if (sz_b > 0) {    
    while (headB->next != headC) {
      ptr = headB;
      headB = headB->next;
      delete ptr;
      ++count;
    }
    delete headB; ++count;
  }
  //printf("%s %d \n", "deallocated ", count);
  if (sz_c > 0) {    
    while (headC->next != NULL) {
      ptr = headC;
      headC = headC->next;
      delete ptr;
      ++count;
    }
    delete headC; ++count;
  }
  //printf("%s %d \n", "deallocated ", count);
  assert(count == sz_a + sz_b + sz_c);

  char z; cin >> z;
  return 0;
}