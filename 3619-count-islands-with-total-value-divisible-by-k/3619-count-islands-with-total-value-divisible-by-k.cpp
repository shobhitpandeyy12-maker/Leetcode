class Solution {
    int m, n;

    int dfs(vector<vector<int>>& grid, int r, int c, int& k){
        if(r < 0 || r >= m || c < 0 || c >= n) return 0;
        if(grid[r][c] == 0) return 0;

        int temp = grid[r][c];
        grid[r][c] = 0;

        int up = dfs(grid, r - 1, c, k);
        int down = dfs(grid, r + 1, c, k);
        int left = dfs(grid, r, c - 1, k);
        int right = dfs(grid, r, c + 1, k);

        return (up + down + left + right + temp) % k;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0)
                    if(dfs(grid, i, j, k) % k == 0) ++count;
            }
        }

        return count;
    }
};