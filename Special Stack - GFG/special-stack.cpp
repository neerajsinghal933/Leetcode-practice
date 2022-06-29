// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends

// int mn = 1000001;
void push(stack<int>& s, int a){
	// Your code goes here
// 	mn = min(mn,a );
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return s.size()==n;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.empty();
}

int pop(stack<int>& s){
	// Your code goes here
	int t = s.top();
	s.pop();
	return t;
}

int getMin(stack<int>& s){
	// Your code goes here
	int ans = 1000000;
	stack<int> temp;
	while(!s.empty()){
	    if(s.top() <= ans){
	        ans = s.top();
	    }
	    temp.push(s.top());
	    s.pop();
	}
	
	while(!temp.empty()){
	    s.push(temp.top());
	    temp.pop();
	}
	
	return ans;
}