class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int ones = ranges::count(s, '1');
        
        vector<int> zero_start, zero_end;
        for(int i = 0; i < n;){
            if(s[i] == '0'){
                int j = i;
                while(j < n && s[j] == '0') ++j;

                zero_start.push_back(i);
                zero_end.push_back(j - 1);

                i = j;
            }else ++i;
        }

        int number_blocks = zero_start.size();
        vector<int> V;
        for(int j = 0; j + 1 < number_blocks; ++j)
            V.push_back((zero_end[j] - zero_start[j] + 1) +
                        (zero_end[j + 1] - zero_start[j + 1] + 1));
        
        int number_valley = V.size();
        vector<vector<int>> sparse{V};
        for(int half = 1; half * 2 <= number_valley; half *= 2){
            auto& prev = sparse.back();
            vector<int> next;
            next.reserve(prev.size() - half);

            for(int i = 0; i + half < prev.size(); ++i){
                next.push_back(max(prev[i], prev[i + half]));
            }
            sparse.push_back(move(next));
        }

        auto rmq = [&](int lo, int hi){
            int t = bit_width(unsigned(hi - lo + 1)) - 1;
            return max(sparse[t][lo], sparse[t][hi - (1 << t) + 1]);
        };

        auto clip = [&](int j, int l, int r){
            return V[j] - max(0, l - zero_start[j]) - max(0, zero_end[j + 1] - r);
        };

        auto gain = [&](int l, int r){
            if(number_blocks < 2) return 0;
            int ja = ranges::lower_bound(zero_end, l) - zero_end.begin();
            int jb = ranges::upper_bound(zero_start, r) - zero_start.begin() - 2;

            if(ja > jb) return 0;
            return max({clip(ja, l, r),
                        clip(jb, l, r),
                        jb - ja >= 2 ? rmq(ja + 1, jb - 1) : 0});
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for(auto& q : queries)
            ans.push_back(ones + gain(q[0], q[1]));
        return ans;
    }
};