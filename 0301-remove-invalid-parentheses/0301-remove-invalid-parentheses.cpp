class Solution {
    void dfs(string& s, int index, int currentRemoved, string& n, unordered_set<string>& ans, int& len, int open){        
        if(currentRemoved > len) return;
        if(open < 0) return;
        if(index == s.length()){
            if(open == 0){
                if(currentRemoved < len){
                    ans.clear();
                    len = currentRemoved;
                }

                ans.insert(n);
            }

            return;
        }

        n += s[index];
        dfs(s, index + 1, currentRemoved, n, ans, len, open + ((s[index] == '(') ? 1 : (s[index] == ')' ? -1 : 0)));
        n.pop_back();
        dfs(s, index + 1, currentRemoved + 1, n, ans, len, open);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> group;

        int len = 0;
        int open = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(') ++open;
            else if(s[i] == ')') --open;

            if(open < 0){
                ++len;
                open = 0;
            }
        }
        len += open;
        string stri = "";
        dfs(s, 0, 0, stri, group, len, 0);
        
        vector<string> ans;
        ans.reserve(group.size());
        for(auto& str : group) ans.push_back(str);
        return ans;
    }
};