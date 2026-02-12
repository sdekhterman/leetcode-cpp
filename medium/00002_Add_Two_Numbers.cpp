/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #include <iostream>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool l1NextNull = (l1->next == nullptr);
        bool l2NextNull = (l2->next == nullptr);
        bool isOverflow = false;
        int valueSum    = l1->val + l2->val;
        if(valueSum > 9) {
            valueSum = valueSum%10;
            isOverflow = true;
        } 

        ListNode* list = new ListNode(valueSum);
        
        if(l1NextNull && !l2NextNull){    
            if(isOverflow) {l2->next->val = (l2->next->val + 1);}
            ListNode* list1 = new ListNode();
            list->next = addTwoNumbers(list1, l2->next);
        } 
        else if(!l1NextNull && l2NextNull){
            if(isOverflow) {l1->next->val = (l1->next->val + 1);}
            ListNode* list2 = new ListNode();
            list->next = addTwoNumbers(l1->next, list2);
        } 
        else if(!l1NextNull && !l2NextNull){
            if(isOverflow) {l2->next->val = (l2->next->val + 1);}
            list->next = addTwoNumbers(l1->next, l2->next);
        } 
        else if(isOverflow){
            ListNode* list1 = new ListNode(1);
            ListNode* list2 = new ListNode();
            list->next = addTwoNumbers(list1, list2);
        }
        return list;
    }
};
