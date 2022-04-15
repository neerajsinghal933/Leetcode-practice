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
    vector<int> nextLargerNodes(ListNode* head) {
        head = fun(head);
        vector<int>ans;
        stack<int>st;
        while(head)
        {
            while(!st.empty() and st.top()<=head->val)
                st.pop();
            if(st.empty())
                ans.push_back(0);
            else
                ans.push_back(st.top());
            st.push(head->val);
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    ListNode* fun(ListNode* head)
    {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp)
        {
            temp = temp->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};