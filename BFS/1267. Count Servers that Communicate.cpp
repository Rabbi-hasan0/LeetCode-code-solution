class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = 255, m = 255;
        bool vis[n + 1][m + 1];
        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                vis[i][j] = false;
            }
        }

        int res = 0; 
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; ++i) { 
            int cnt = 0;
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    cnt++;
                    vis[i][j] = true;
                }
            }
            if(cnt <= 1) {
                for(int j = 0; j < m; ++j) {
                    vis[i][j] = false;
                }
            }
            res += (cnt > 1 ?cnt : 0);
        }

        for (int i = 0; i < m; ++i) {
            int cnt = 0, v = 0;
            for(int j = 0; j < n; ++j) {
                if(grid[j][i] == 1) {
                    cnt++;
                    if(vis[j][i]) v++;
                    vis[j][i] = true;
                }
            }
            res += (cnt > 1 ?(cnt - v) : 0);
        }
        return res;
    }
};
