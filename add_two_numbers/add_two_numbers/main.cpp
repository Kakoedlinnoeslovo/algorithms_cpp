//
//  main.cpp
//  add_two_numbers
//
//  Created by Roman Degtyarev on 30.06.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>

struct ListNode {
         int val;
         ListNode *next;
        ListNode(int x) : val(x), next(NULL) {};
public:
    void print();
    
};

void ListNode::print(){
    ListNode *head = this;
    int i = 0;
    while (head){
        std::cout<<i << ": "<< head->val<<std::endl;
        head = head->next;
        i++;
    }
    
};





class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) ;
    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2);
};



long long calc_sum(ListNode *left, ListNode *right){
    ListNode *l = left;
    ListNode *r = right;
    long long sum = 0;
    int k = 1;
    while(l or r){
        if (l != NULL and r!=NULL){
            sum += l->val * k + r->val *k;
            k*=10;
            l = l->next;
            r = r->next;
        }
        else if (l== NULL and r!= NULL){
            sum+=r->val *k;
            k*=10;
            r = r->next;
        }
        else if (l != NULL and r == NULL){
            sum+=l->val *k;
            k*=10;
            l = l->next;
        }
        else break;
    }
    return sum;
};


ListNode *Solution::addTwoNumbers(ListNode* l1, ListNode* l2){
    long long sum;
    sum = calc_sum(l1, l2);
    ListNode* result = new ListNode(sum %10);
    ListNode* head = result;
    sum = sum/10;
    while (sum !=0){
        ListNode* temp = new ListNode(sum%10);
        sum = sum / 10;
        result->next = temp;
        result = result->next;
    }
    return head;
};

ListNode *Solution::addTwoNumbers2(ListNode *l1, ListNode *l2){
  
    ListNode *cur1 = new ListNode(0);
    ListNode *cur2 = new ListNode(0);
    cur1-> next = l1;
    cur2 -> next = l2;
    int carry = 0;
    
    while (cur1->next !=NULL || cur2->next != NULL){
        if (cur1->next != NULL){
            cur1->next->val += cur2->next == NULL? carry : cur2->next->val + carry;
        }
        else{
            cur1->next = cur2->next;
            cur2 = new ListNode(0);
            cur1->next->val +=carry;
        }
        carry = (cur1->next->val) /10;
        cur1->next->val %=10;
        if (cur1->next) cur1 = cur1->next;
        if (cur2->next) cur2 = cur2->next;
        
    }
    if (carry == 1){
        cur1->next = new ListNode(1);
    };
    return l1;
};


int main(int argc, const char * argv[]) {
    ListNode* left = new ListNode(9);
//    left->next = new ListNode(4);
//    left->next->next = new ListNode(3);
    //left->print();
//
//
    ListNode* right = new ListNode(1);
    right->next = new ListNode(9);
    right->next->next = new ListNode(9);
    right->next->next->next = new ListNode(9);
    right->next->next->next->next = new ListNode(9);
    right->next->next->next->next->next = new ListNode(9);
    right->next->next->next->next->next->next = new ListNode(9);
    right->next->next->next->next->next->next->next = new ListNode(9);
    right->next->next->next->next->next->next->next->next = new ListNode(9);
    right->next->next->next->next->next->next->next->next->next = new ListNode(9);
    //right->print();
//    int summa;
//    summa = sum(left, right);
        ListNode* result;
//    result = Pafss(summa);
    
    Solution sol;
    result = sol.addTwoNumbers2(left, right);
    result->print();
    return 0;
}
