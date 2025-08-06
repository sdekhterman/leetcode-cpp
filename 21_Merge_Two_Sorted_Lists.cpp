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
        if((list1 == nullptr) && (list2 == nullptr))       {return nullptr;}
        else if ((list1 != nullptr) && (list2 == nullptr)) {return mergeList1(list1, list2);}
        else if ((list1 == nullptr) && (list2 != nullptr)) {return mergeList2(list1, list2);} 
        else if (list1->val < list2->val)                  {return mergeList1(list1, list2);} 
        else                                               {return mergeList2(list1, list2);}

        return nullptr;
    }
private:
    ListNode dummy(0);
    ListNode* tail = &dummy;
    ListNode* mergeList1(ListNode* list1, ListNode* list2) {
        if (!list1->next) {
            ListNode* node = new ListNode(list1->val, mergeTwoLists(nullptr, list2));
            return node;
        } else if (!list1->next->next) {
            ListNode* tail = new ListNode(list1->next->val);
            ListNode* node = new ListNode(list1->val, mergeTwoLists(tail, list2));
            return node;
        } else {
            ListNode* tail = new ListNode(list1->next->val, list1->next->next);
            ListNode* node = new ListNode(list1->val, mergeTwoLists(tail, list2));
            return node;
        }
    }

    ListNode* mergeList2(ListNode* list1, ListNode* list2) {
        if (!list2->next) {
            ListNode* node = new ListNode(list2->val, mergeTwoLists(list1, nullptr));
            return node;
        } else if (!list2->next) {
            ListNode* tail = new ListNode(list2->next->val);
            ListNode* node = new ListNode(list2->val, mergeTwoLists(list1, tail));
            return node;
        } else {
            ListNode* tail = new ListNode(list2->next->val, list2->next->next);
            ListNode* node = new ListNode(list2->val, mergeTwoLists(list1, tail));
            return node;
        }
    }
};
