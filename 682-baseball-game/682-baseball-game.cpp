class Solution {
public:
     int calPoints(vector<string>& ops) {
        stack<int> s;
       
        
    for(int i =0; i<ops.size(); i++){
        
        if(ops[i]=="C"){
            s.pop();
        }
        else if(ops[i]=="D"){
            int a = s.top();
            s.push(2*a);
        }
        else if(ops[i]=="+"){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b);
            s.push(a);
            s.push(a+b);
        }
        
        else{
            //cout<<ops[i]<<endl;
            s.push(stoi(ops[i]));
        }
       
    }
        int ans =0;           
        while(!s.empty()){
            ans += s.top();
            //cout<<s.top()<<endl;
            s.pop();
        }
    return ans;
        
    }
};