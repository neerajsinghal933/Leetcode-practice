class Solution {
public:
    bool isValid(string s) {
            
           stack<char>st;
            int n=s.size();
            //cout<<st.size();
            if(n==1){
                    return false;
            }
            int c=0;
            for(int i=0;i<n;i++){
                    
                    if(s[i]=='('||s[i]=='{'||s[i]=='['){
                            st.push(s[i]);
                            
                    }
                    else {
                            //cout<<st.size();
                            if(st.size()>0){
                                    if(s[i]==')'&&st.top()=='('){
                                    st.pop();
                                    c=c+2;
                                    
                            }
                            if(s[i]=='}'&&st.top()=='{'){
                                    st.pop();
                                   c=c+2;
                            }
                            if(s[i]==']'&&st.top()=='['){
                                    st.pop();
                                    c=c+2;
                            }
                                    
                            }
                    }
            }
            
            if(c==n){
                return true;
            }
            return false;
        
    }
};