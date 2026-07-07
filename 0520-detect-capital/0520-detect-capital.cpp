class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital_count = 0;
        
        // Count total uppercase letters
        for (char c : word) {
            if (isupper(c)) {
                capital_count++;
            }
        }
        
        // Rule 1: All caps OR Rule 2: All lowercase
        if (capital_count == word.length() || capital_count == 0) {
            return true;
        }
        
        // Rule 3: Only the first letter is capital
        if (capital_count == 1 && isupper(word[0])) {
            return true;
        }
        
        return false;
    }
};
        



    