class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size(), i;

        for(int i = 0; i < n; ++i)
            nums[i] = abs(nums[i]);
        nth_element(nums.begin(), nums.begin() + (n >> 1), nums.end());

        long long res = 0;
        for(i = 0; i < (n >> 1); ++i)
            res -= nums[i] * nums[i];
        for(; i < n; ++i)
            res += nums[i] * nums[i];
        
        return res;
    }
};