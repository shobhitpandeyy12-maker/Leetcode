class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi= *max_element(costs.begin(), costs.end());

        vector<int> freq(maxi+1,0);
        for(int i=0; i<costs.size(); i++)
        {
            freq[costs[i]]++;
        }

        int i=0;
        int j=0;
        while(i<costs.size())
        {
            while(freq[j]!=0)
            {
                costs[i]=j;
                i++;
                freq[j]--;
            }
            j++;

        }

        int count=0;
        for(int &c:costs)
        {
            if(c<=coins){
                count++;
                coins-=c;
            }
        }

        return count;
        
    }
};