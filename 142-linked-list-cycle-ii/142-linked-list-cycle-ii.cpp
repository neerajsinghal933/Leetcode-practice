/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL)
            return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        do{
            slow = slow->next;
            if(!fast || !fast->next)
                return NULL;
            fast = fast->next->next;
        }while(slow!=fast);
        
        slow= head;
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};