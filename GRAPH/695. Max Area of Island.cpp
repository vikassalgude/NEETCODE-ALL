class Solution {
public:
    int r, c;
    bool valid(int i, int j) {
        return (i >= 0 && i < r && j >= 0 && j < c);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        r = grid.size();
        c = grid[0].size();
        int ans = 0;
        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    int area=0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0; // Mark as visited
                    while (!q.empty()) {
                        int a = q.front().first;
                        int b = q.front().second;
                        q.pop();area++;
                        for (int k = 0; k < 4; k++) {
                            int ni = a + row[k];
                            int nj = b + col[k];
                            if (valid(ni, nj) && grid[ni][nj] == 1) {
                                q.push({ni, nj});
                                grid[ni][nj] = 0; // Mark as visited
                            }
                        }
                    }
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};
