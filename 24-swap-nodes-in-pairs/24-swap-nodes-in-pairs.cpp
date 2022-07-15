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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* third = second->next;
        
        head = second;
        head->next = first;
        first->next = swapPairs(third);
        return head;
        
    }
};