//
//  main.cpp
//  remove_nth_node_from_end_of_list
//
//  Created by Roman Degtyarev on 07.09.2018.
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
    int recurcive_walk(ListNode* head, int n, int k, int &tot_long){
        if (head ->next){
            int temp = recurcive_walk(head->next, n, k + 1, tot_long);
            if (temp == -1 and head->next){
                if (head->next->next){
                    head->next = head->next->next;
                }
                else{
                    head->next = NULL;
                }
                return temp - 1;
            }
            if (temp == 0 and n == tot_long and head ->next){
                ListNode* new_head = new ListNode(0);
                new_head = head ->next;
                *head = *new_head;
            }
            return temp - 1;
        }
        else{
            tot_long = k;
            return n - 1;
        }
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tot_long = 0;
        if (head->next == NULL){
            return NULL;
        }
        recurcive_walk(head, n - 1, 0, tot_long);
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    sol.removeNthFromEnd(head, 2);
    
    while(head){
        cout << head->val;
        head = head ->next;
        
    }
    return 0;
}
