class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        double x = log(n) / log(4.0);

        return abs(x - round(x)) < 1e-10;
        
    }
};