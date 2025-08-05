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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1->val >= list2->val){
            ListNode node(list1->val, mergeTwoLists(list1, list2));
            return &node;
        } else{
            list2->next
            ListNode node(list2->val, mergeTwoLists(list1, list2));
            return &node;
        }
        // try reducing the size of list1 and list2 as you add a value 
    }
};
