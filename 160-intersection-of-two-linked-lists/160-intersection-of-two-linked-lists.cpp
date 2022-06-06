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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp;
int cnt1=0,cnt2=0;
temp = headA;
while(temp!=NULL)
{
cnt1++;
temp = temp->next;
}
temp = headB;
while(temp!=NULL)
{
cnt2++;
temp = temp->next;
}
int diff = abs(cnt1 - cnt2);
if(cnt1 > cnt2)
{
while(diff--)
headA = headA->next;
}
else
{
while(diff--)
headB = headB->next;
}
while(headA != NULL)
{
if(headA==headB)
return headA;
headA = headA->next;
headB = headB->next;
}
return NULL;
    }
};