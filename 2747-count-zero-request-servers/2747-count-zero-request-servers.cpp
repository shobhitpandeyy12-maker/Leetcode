class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        
        sort(logs.begin(), logs.end(), [](const vector<int>& A, const vector<int>& B){
            return A[1] < B[1];
        });

        int q = queries.size();
        vector<int> idx(q);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j){
            return queries[i] < queries[j];
        });

        vector<int> ans(q);
        vector<int> freq(n + 1);
        int left = 0;
        int right = 0;
        int active = 0;

        for(int i : idx){
            int que = queries[i];
            while(right < logs.size() && logs[right][1] <= que){
                int id = logs[right++][0];
                if(freq[id]++ == 0) ++active;
            }

            while(left < right && logs[left][1] < que - x){
                int id = logs[left++][0];
                if(--freq[id] == 0) --active;
            }

            ans[i] = n - active;
        }

        return ans;
    }
};