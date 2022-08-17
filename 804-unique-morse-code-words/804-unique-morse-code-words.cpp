class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string , char>m;
        for(string word: words)
        {
            string t = "";
            for(char c:word)
            {
                t += v[c-'a'];
            }
            m[t]++;
        }
        return m.size();
    }
};