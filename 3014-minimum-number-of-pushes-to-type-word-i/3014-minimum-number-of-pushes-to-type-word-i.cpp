class Solution {
public:
    int minimumPushes(string word) {
        int m=word.length();
        int d=m/8;
        int r=m%8;


        return ((d+1)*(4*d+r));
        
    }
};