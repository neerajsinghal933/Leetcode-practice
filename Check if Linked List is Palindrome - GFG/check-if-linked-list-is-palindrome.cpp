// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    void reverse(Node** node)
    {
        Node* prev = NULL;
        Node* curr = *node;
        Node* next;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        *node = prev;
    }
    
    bool fun(Node* n1, Node* n2)
    {
        Node* t1 = n1;
        Node* t2 = n2;
        while(t1 and t2)
        {
            if(t1->data!=t2->data)
                return false;
            t1 = t1->next;
            t2 = t2->next;
        }
        if(!t1 and !t2)
            return 1;
            return 0;
    }
    
    void printNode(Node* t)
    {
        while(t)
        {
            cout<<t->data<<" ";
            t = t->next;
        }
    }
  
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        // cout<<"K";
        Node* slow = head, *fast = head;
        Node* second, *prev = head;
        Node* mid = NULL;
        bool res = true;
        if(head and head->next)
        {
            
            while(fast and fast->next)
            {
                fast = fast->next->next;
                prev = slow;
                slow = slow->next;
            }
            if(fast)
            {
                mid = slow;
                slow = slow->next;
            }
            second = slow;
            prev->next = NULL;
            reverse(&second);
            // printNode(head);
            res = fun(head, second);
            reverse(&second);
            if(mid)
            {
                prev->next = mid;
                mid->next = second;
            }
            else
                slow->next = prev;
        }
        return res;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends