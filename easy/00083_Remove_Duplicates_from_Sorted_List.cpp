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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) {return head;}
        
        // best solution on leetcode moved a pointer along the linked list to modify the list (head still point to the front)
        // ListNode* cur = head;
        // while (cur->next != nullptr) {
        //     if (cur->val == cur->next->val) {
        //         cur->next = cur->next->next;
        //     } else {
        //         cur = cur->next;
        //     }
        // }
        
        if(head->next != nullptr){
            if(head->val == head->next->val) {
                if(head->next->next != nullptr) {
                    head->next = head->next->next;
                    head = deleteDuplicates(head);
                }
                else{
                    head->next = nullptr;
                }
            } 
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
};
