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
    
//     ListNode* fun(ListNode* head, int l, int r)
//     {
//         ListNode* t = head;
//         ListNode* prev = NULL;
//         ListNode* curr = head; 
//         for(int i=0;i<=(r-l);i++)
//         {
//             curr = head->next;
//             head->next = prev;
//             prev = head;
//             head = curr;
//         }
//         t->next = curr;
//         while(prev)
//         {
//             cout<<prev->val<<" ";
//             prev = prev->next;
//         }
//         // cout<<prev->val<<" ";
//         return prev;
        
//     }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 0;
        
        ListNode* x = new ListNode(-1);
        ListNode* temp = x; 
        x->next = head;
        // temp = x;
        if(left==right)
            return head;
        
        while(cnt<left-1)
        {
            cnt++;
            // x = x->next;
            temp = temp->next;
        }
        ListNode* cur = temp->next;
        // cout<<temp->val<<endl;
        // x->next = fun(temp, left, right);
        // cout<<temp->val;
        // cout<<temp->val;
        // while(temp)
        // {
        //     cout<<temp->val<<" ";
        //     temp = temp->next;
        // }
        
        for(int i=0;i<(right-left);i++)
        {
            ListNode* p = temp->next;
            temp->next = cur->next;
            cur->next = cur->next->next;
            temp->next->next = p;
        }
        return x->next;
    }
};