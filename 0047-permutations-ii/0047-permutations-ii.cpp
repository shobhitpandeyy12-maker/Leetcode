class Solution {
public:
void permut(vector<int> &arr, vector<vector<int> > &ans, int index){
    vector<bool> used(21,0);
    //base condition
    if(index==arr.size()){
    ans.push_back(arr);
    return;
    }


    for(int i=index; i<arr.size(); i++){
        if(used[arr[i]+10]==0){
            swap(arr[index],arr[i]);
            permut(arr, ans ,index+1);
            swap(arr[index],arr[i]);
            used[arr[i]+10]=1;
    }
    }
}


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> >ans;
        int index;
        permut(nums,ans,0);

        return ans;
        
        
        
    }
};