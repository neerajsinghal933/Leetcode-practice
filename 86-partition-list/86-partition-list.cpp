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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1);
        ListNode* small_head = small;
        ListNode* large = new ListNode(-1);
        ListNode* large_head = large;
        while(head)
        {
            if(head->val<x)
            {
                // ListNode* d = new ListNode(head->val);
                small->next = head;
                small = small->next;
                head = head->next;
                small->next = NULL;
            }
            else
            {
                // ListNode* d = new ListNode(head->val);
                large->next = head;
                large = large->next;
                head = head->next;
                large->next = NULL;
            }
            
        }
        small->next = large_head->next;
        return small_head->next;
    }
};