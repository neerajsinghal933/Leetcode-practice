class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int i=num.length()-2;
        
        for(;i>=0 ;i--)
        {
            if(num[i]<num[i+1])
            {
                int j=i;
                while(j+1<num.length()&&num[j+1]>num[i])
                {   
                    j++;
                }
                int x=num[i];
                num[i]=num[j];
                num[j]=x;
                sort(num.begin()+i+1,num.end());
                break;
            }
        }
        long long ans= stol(num);
        if(ans>INT_MAX||i==-1)
        {
            return -1;
        }
        return (int)ans;
    }
};