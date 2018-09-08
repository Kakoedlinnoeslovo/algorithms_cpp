//
//  main.cpp
//  merge_two_sorted_lists
//
//  Created by Roman Degtyarev on 08.09.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
using namespace std;




struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* recursive_merge(ListNode* l1, ListNode* l2, ListNode* result){
        if (l1 && l2){
            if (l1->val <= l2->val) {
                result = new ListNode(l1->val);
                result->next = recursive_merge(l1->next, l2, result->next);
                return result;
            }
            else{
               result = new ListNode(l2->val);
               result->next = recursive_merge(l1, l2->next, result->next);
                return result;
            }
        }
        else{
            if (l1){
                result = new ListNode(l1->val);
                result->next = recursive_merge(l1->next, l2, result->next);
                return result;
            
            }
            if (l2){
                result = new ListNode(l2->val);
                result->next = recursive_merge(l1, l2->next, result->next);
                return result;
            }
        }
        return result;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 || l2){
            ListNode* answer = new ListNode(0);
            answer = recursive_merge(l1, l2, answer);
            return answer;
        }
        return NULL;
    }
};


int main() {
    
    ListNode *a = new ListNode(-9);
    a->next = new ListNode(3);
    a->next->next = new ListNode(4);
    
    ListNode *b = NULL;
    //b->next = new ListNode(8);
    //b->next->next = new ListNode(4);
    
    Solution sol;
    ListNode *head = sol.mergeTwoLists(a, b);
    
    while(head){
        cout << head ->val;
        head = head -> next;
    }
    
    
    
    return 0;
}
