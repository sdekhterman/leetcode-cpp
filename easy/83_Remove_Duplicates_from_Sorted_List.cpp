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
