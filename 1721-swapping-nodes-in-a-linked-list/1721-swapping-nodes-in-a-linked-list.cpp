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
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt = 0;
        ListNode* t = head;
        while(t!=NULL)
        {
            cnt++;
            t = t->next;
        }
        ListNode* first = head;
        ListNode* second = head;
        int n = cnt-k;
        int i=1;
        while(i<=n)
        {
            i++;
            first = first->next;
        }
        i=1;
        while(i<k)
        {
            i++;
            second = second->next;
        }
        cout<<first->val<<" "<<second->val;
        swap(first->val, second->val);
        return head;
    }
};