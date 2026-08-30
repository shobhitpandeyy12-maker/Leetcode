class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n= nums.size();

        int maxElement=INT_MIN, maxidx;
        int minElement=INT_MAX,minidx;


        for(int i=0; i<n; i++){
            if(nums[i] > maxElement){
            maxElement=nums[i];
            maxidx=i;
            }

            if(nums[i] < minElement){
            minElement=nums[i];
            minidx=i;
            }
        }

        //removing both the elemnt from left
        int c1=max(maxidx, minidx)+1;

        //removing both from the right

        int c2=n - min(maxidx, minidx);

        //bonus
        int c3=min(minidx, maxidx)+1 +n-max(minidx, maxidx);


        return min({c1, c2, c3});

        
    }
};
