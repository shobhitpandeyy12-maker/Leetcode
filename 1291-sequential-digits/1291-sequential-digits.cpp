class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        //using sliding window technique 
        string s="123456789";
        //keeping in mind the constarints
        vector<int> ans;
        for(int len=2; len<10; len++)
        {
            for(int start=0 ; start<=s.length()-len; start++){
            int digit=stoi(s.substr(start,len));

            if(digit >=low && digit <=high)
            {
                ans.push_back(digit);
            }
            }
        }
        


        return ans;
        
    }
};