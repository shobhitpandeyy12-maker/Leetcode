class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;

        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                stk.push(-1);
            }else{
                int temp = 0;
                while(stk.top() != -1){
                    temp += stk.top();
                    stk.pop();
                }
                stk.pop();
                if(temp != 0) stk.push(2 * temp);
                else stk.push(1);
            }

            // cout << stk.top() << endl;
        }

        int ans = 0;
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};