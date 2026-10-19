const int LIMIT = 1e9 + 7;

vector<vector<long long>> C(1001, vector<long long>(10001));
auto init = [](){
    for(int i = 0; i < 1001; ++i){
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % LIMIT;
    }

    return false;
}();

class Solution {
private:
    int ways(vector<int> nums){
        if(nums.size() <= 2) return 1;
        vector<int> left;
        vector<int> right;

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        return C[nums.size() - 1][left.size()] * ways(left) % LIMIT * ways(right) % LIMIT;
    }
public:
    int numOfWays(vector<int>& nums) {
        return (ways(nums) - 1) % LIMIT;
    }
};