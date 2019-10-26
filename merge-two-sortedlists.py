# -*- coding: utf-8 -*-
"""
Created on Sat Oct 26 01:03:09 2019

@author: rice-cake

Problem 21 (Easy):

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the 
first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # when either or both are empty lists        
        try:
            l1.val
        except AttributeError:
            return l2
        try:
            l2.val
        except AttributeError:
            return l1

        # another way to check, from posted solutions
#        if not l1:
#            return l2
#        if not l2:
#            return l1
        # doesn't work without the not, why?
#        if (l1 is not None): return l2
#        if (l2 is not None): return l1
        
        # print('Lists not empty')
        # switch the lists
        if l1.val > l2.val: 
            l1, l2 = l2, l1
#            t1 = l2
#            l2 = l1
#            l1 = t1

        print_list(l1)
        print_list(l2)        
            
        # keep including the second list into the first, 
        # and exhausting the second list
        p1, p2 = l1, l2
        while p2 != None:            
            while p1.val <= p2.val:
                t1 = p1 # keep track of the previous node
                # print('in', t1.val, p1.val, p2.val)                         
                if p1.next == None: # at end of l1
                    p1.next = p2
                    return l1
                p1 = p1.next

            # print('out', t1.val, p1.val, p2.val)                
            t1.next = p2
            t2 = p2.next
            p2.next = p1
            t1 = t1.next
            p2 = t2
        
        # print_list(l1)
        return l1


# test driver

def make_list(a: list) -> ListNode:
    """ make a singly linked list from a list
        and return the head of the list 
    """    
    if len(a) < 1: # empty
        print ('Input list is empty')
        return ListNode
    head = ListNode(a[0])
    p = head
    for e in a[1:]:
        p.next = ListNode(e)
        p = p.next    
    return head


def print_list(l: ListNode):
    """ print a singly linked list from head to tail
    """
    try:
        l.val
    except AttributeError:
        print('List is empty')
        return
    print(l.val, end='')
    while l.next != None:
        l = l.next
        print(' ->', l.val, end='')
    print()

# print_list(make_list([3,4,5]))

sol = Solution
print(sol.mergeTwoLists(sol, [], []), "\n")
print_list(sol.mergeTwoLists(sol, [], make_list([2,3])))
print()
print_list(sol.mergeTwoLists(sol, make_list([5]), make_list([4,8])))
print()
print_list(sol.mergeTwoLists(sol, make_list([5,6,7]), make_list([7,8])))
print()
print_list(sol.mergeTwoLists(sol, make_list([5,6,9]), make_list([7,8])))
print()
print_list(sol.mergeTwoLists(sol, make_list([5,6,9]), make_list([4,8])))
print()

        


