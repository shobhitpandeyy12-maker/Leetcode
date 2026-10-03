class Solution {
public:
    int longestValidParentheses(string s) {
        int start = 0;      // left edge of the forward window
        int open = 0;       // balance of s[start .. i]
        int longest = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ')') --open;
            else ++open;

            // Too many ')'. Drop from the left until the balance is healthy.
            while (open < 0) {
                if (s[start] == '(') --open;  // undo a '('
                else ++open;                  // undo a ')'
                ++start;
            }

            // Same number of each, and we never went negative: valid window.
            if (open == 0) longest = max(longest, i - start + 1);
        }

        // Same scan from the right, so a leftover '(' can be trimmed.
        start = s.length() - 1;
        open = 0;

        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == ')') ++open;  // ')' is the "open" from the right
            else --open;

            while (open < 0) {
                if (s[start] == '(') ++open;
                else --open;
                --start;
            }

            if (open == 0) longest = max(longest, start - i + 1);
        }

        return longest;
    }
};