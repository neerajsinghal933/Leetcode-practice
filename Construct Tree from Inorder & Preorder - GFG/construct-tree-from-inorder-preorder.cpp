// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int idx = 0;
    int find(int in[], int x, int s, int e)
    {
        for(int i=s;i<=e;i++)
        {
            if(in[i]==x)
                return i;
        }
    }
    
    Node* fun(int in[], int pre[], int s, int e)
    {
        if(s>e)
            return NULL;
        int root = pre[idx++];
        Node* temp = new Node(root);
        if(s==e)
            return temp;
        int pos = find(in, root, s, e);
        temp->left = fun(in, pre, s, pos-1);
        temp->right = fun(in, pre, pos+1, e);
        return temp;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return fun(in, pre, 0, n-1);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends