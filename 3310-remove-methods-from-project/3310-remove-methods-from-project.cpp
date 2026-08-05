class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int> > edges(n);
        vector<int> indegree(n,0);
        vector<bool> suspicious(n);

        for(const auto &inv : invocations){
            edges[inv[0]].push_back(inv[1]);
            indegree[inv[1]]++;
        }

        queue<int> q;
        q.push(k);
        suspicious[k]= true;

        while(!q.empty()) {
            int u=q.front();
            q.pop();
            for(int v : edges[u]){
                indegree[v]--;

                if (!suspicious[v]){
                    q.push(v);
                    suspicious[v]= true;
                }
            }
        }
        bool canremoveAll=true;
        vector<int> remaining;

        for (int i =0; i<n; i++){
            if( suspicious[i] && indegree[i]>0){
                canremoveAll= false;
                break;
            }
            else if(!suspicious[i]){
                remaining.push_back(i);
            }
            }

            if (!canremoveAll) {
                vector<int> allnodes(n);
                iota(allnodes.begin(), allnodes.end(),0);
                return allnodes;
            }
        
        return remaining ;
    }
        
    
};