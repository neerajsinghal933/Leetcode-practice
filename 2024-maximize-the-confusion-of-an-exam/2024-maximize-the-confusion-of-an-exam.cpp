class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0, j=0;
        int n = answerKey.size();
        int ans = 0, cnt = 0;
        map<char, int>m;
        while(i<n)
        {
            m[answerKey[i]]++;
            cnt = max(cnt, m[answerKey[i]]);
            if(i-j+1 - cnt >k)
            {
                m[answerKey[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};