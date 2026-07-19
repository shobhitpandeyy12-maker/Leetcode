class Solution {
public:
    bool isPowerOfThree(int n) {

        //using logic of mathematics & logarithmic
        
         if (n <= 0) return false;

        double x = log(n) / log(3.0);

        return abs(x - round(x)) < 1e-10;
    }
};