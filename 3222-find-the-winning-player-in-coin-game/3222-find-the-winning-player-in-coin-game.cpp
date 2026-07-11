class Solution {
public:
    string winningPlayer(int x, int y) {
        int count = 0;
        int iteration = x;
        for(int i=0;i<iteration;i++)
        {
            if(x>=1 && y>=4)
            {
                x = x-1;
                y = y-4;
                count++;
            }
        }

        if(count %2 != 0)
        {
            return "Alice";
        }
        return "Bob";
        
    }
};