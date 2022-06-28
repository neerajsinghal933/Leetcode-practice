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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        if(n==0)
            return NULL;
        
        ListNode* c = lists[0];
        if(n==1)
            return c;
        ListNode* ans = c;
        
        for(int i=0;i<n-1;i++)
        {
            c = merge(c, lists[i+1]);
            // c = c->next;
        }
        return c;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* c;
        if(l1->val < l2->val)
        {
            c = l1;
            c->next = merge(l1->next, l2);
        }
        else
        {
            c = l2;
            c->next = merge(l1, l2->next);
        }
        return c;
    }
};