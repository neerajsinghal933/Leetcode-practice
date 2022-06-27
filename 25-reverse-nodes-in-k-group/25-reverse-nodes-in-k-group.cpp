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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* t = head, *start, *prev, *next_node, *start_prev;
        while(t)
        {
            n++;
            t = t->next;
        }
        int cnt = n/k;
        t = head;
        for(int i=0;i<cnt;i++)
        {
            prev = NULL;
            start = t;
            for(int j=0;j<k;j++)
            {
                next_node = t->next;
                t->next = prev;
                prev = t;
                t = next_node;
            }
            if(i==0)
                head = prev;
            else
                start_prev->next = prev;
            start_prev = start;
        }
        if(start)
            start->next = t;
        return head;
    }
};