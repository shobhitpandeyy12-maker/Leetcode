class Solution {
public:
    int climbStairs(int n) {
        // code here
        if(n<=1)
        return 1;
        
        
        int s1=1;
        int s2=1;
        for(int i=2; i<=n; i++){
            
            int current=s1+s2;
            s1=s2;
            s2=current;
            
        }
        
        return s2;
        
    
        
            
        
        
    

        
    }
};