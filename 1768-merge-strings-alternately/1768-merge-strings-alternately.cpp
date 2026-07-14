class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int a=word1.length();
        int b=word2.length();

        string ans;
        while(a>0 && b>0)
        {
            ans+=word1[word1.length()-a];
            ans+=word2[word2.length()-b];
            --a;
            --b;

        }
        while(a>0)
        {
            ans+=word1[word1.length() -a];
            a--;
        }

        while(b>0)
        {
            ans+=word2[word2.length()-b];
            b--;
        }

        return ans;


        
    }
};