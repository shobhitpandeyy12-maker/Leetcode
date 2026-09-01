class Solution {
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        int sx = 0, sy = 0;
        int cnt = 0;

        for(int i = 0; i < classroom.size(); ++i){
            for(int j = 0; j < classroom[i].size(); ++j){
                if(classroom[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }else if(classroom[i][j] == 'L'){
                    dp[i][j] = 1 << cnt++;
                }
            }
        }

        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << cnt, -1)));
        bestEnergy[sx][sy][0] = energy;

        struct Info {
            int x, y, mask, e, steps;
        };

        queue<Info> q;
        q.push({sx, sy, 0, energy, 0});

        while(!q.empty()){
            Info t = q.front();
            q.pop();

            if(t.mask == (1 << cnt) - 1) return t.steps;
            if(t.e == 0) continue;

            for(int i = 0; i < 4; ++i){
                int nx = t.x + dir[i][0];
                int ny = t.y + dir[i][1];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n || classroom[nx][ny] == 'X') continue;

                int ne = classroom[nx][ny] == 'R' ? energy : t.e - 1;
                int nmask = t.mask | dp[nx][ny];

                if(ne > bestEnergy[nx][ny][nmask]){
                    bestEnergy[nx][ny][nmask] = ne;
                    q.push({nx, ny, nmask, ne, t.steps + 1});
                }
            }
        }

        return -1;
    }
};