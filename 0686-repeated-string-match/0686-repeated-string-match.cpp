class Solution {
public:
void lpsfind(vector<int>&lps, string s) {
        // code here
        
        
        
        int pre=0 , suf=1 ;
        while(suf < s.size())
        {
            if(s[pre]==s[suf])
            {
                lps[suf]=pre+1;
                suf++, pre++;
                
            }
            else
            {
                if(pre==0)
                {
                    lps[suf]=0;
                    suf++;
                }
                else
                {
                    pre=lps[pre-1];
                }
            }
        }
        
        
            
        
    }

    int kmp_match(string haystack, string needle) {
    
        vector<int>lps(needle.size(),0);
        lpsfind(lps,needle);

        int first=0, second=0;

        while(first<haystack.size() && second<needle.size())
        {
            //match
            if(haystack[first]==needle[second])
            {
                first++, second++;
            }
            //not  matched
            else
            {
                if(second==0)
                first++;
                else
                second=lps[second-1];

            }
        }


        // agar answer exist kiy toh phir
        if(second==needle.size())
        return 1;

        return 0;
    }





    int repeatedStringMatch(string a, string b) {
        
        if(a==b)
        {
            return 1;
        }
        int repeat=1;
        string temp=a;

        while(temp.size()<b.size())
        {
            temp+=a;
            repeat++;
        }
        //kmp pattern search

        if(kmp_match(temp,b)==1)

        return repeat;
        

        //temp+a, kmp search
        if(kmp_match(temp+a,b)==1)
        {
            return repeat+1;
        }


        return -1;
    }   

};