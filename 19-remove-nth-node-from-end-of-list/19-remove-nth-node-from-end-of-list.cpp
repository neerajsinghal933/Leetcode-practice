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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = countNode(head);
        int k = cnt - n;
        if(n==cnt)
            return head->next;
        ListNode* temp = head;
        while(k>1)
        {
          temp = temp->next;  
            k--;
        }
        // cout<<temp->val;
        temp->next = temp->next->next;
        return head;
        
    }
    
    int countNode(ListNode* head)
    {
        int cnt = 0;
        while(head)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
};