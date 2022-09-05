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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<vector<ListNode*>>vec;
        int curr=1;
        while(head)
        {
            vector<ListNode*>v;
            int k=curr;
            while(k-- and head)
            {
                v.push_back(head);
                head = head->next;
            }
            vec.push_back(v);
            curr++;
        }
        ListNode* res = new ListNode(0);
        ListNode* dummy = res;
        for(auto it:vec)
        {
            vector<ListNode*>temp=it;
            if(temp.size()%2==0)
            {
                reverse(temp.begin(), temp.end());
            }
            for(auto i:temp)
            {
                res->next = i;
                res = res->next;
            }
        }
        res->next = NULL;
        return dummy->next;
        
    }
};