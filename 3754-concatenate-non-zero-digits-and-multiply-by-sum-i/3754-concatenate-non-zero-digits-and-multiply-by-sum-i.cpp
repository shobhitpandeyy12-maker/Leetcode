class Solution {
public:
    long long sumAndMultiply(int n) {

        
        long long sum=0;
        long long rev=0;

        while(n>0)
        {
            int dig=n%10;
            if(dig!=0)
            {
                sum+=dig;
                rev=rev*10+dig;//this shall give us the reverse of the number without the zeroes

            }
            n/=10;

        }
        if(rev==0)
        return 0;//handles the 0 number of test case
        long long num=0;
        //now we shall get the number by reversing it finally

        while(rev>0)
        {
            num=num*10+rev%10;
            rev/=10;
        }
        return num*sum;


        
    }
};