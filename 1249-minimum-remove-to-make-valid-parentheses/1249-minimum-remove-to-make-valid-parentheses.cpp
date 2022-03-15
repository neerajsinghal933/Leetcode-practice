class Solution {
public:
string minRemoveToMakeValid(string s)
{
int front=0,back=0;
    int cnt = 0;

    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='(')
      {
          front++;
         
      }
        if(s[i]==')')
        {
            back++;
        }
        if(back>front)
        {
            back--;
            s.erase(s.begin()+i);cnt++;
            i--;
        }
    }
   
   for(int i=s.size()-1;i>=0;i--)
   {
       if(front>back && s[i]=='(')
       {
          s.erase(s.begin()+i);
          
           front--;
           cnt++;
        }  
       if(front==back)break;
       
   }
    cout<<cnt;
    return s;
    
}
};

