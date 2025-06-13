class Solution {
public:
    int r, c;
    bool valid(int row1, int col1) {
        return (row1 >= 0 && row1 < r && col1 >= 0 && col1 < c);
    }
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int ans = -1;
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0) return 0; // No fresh oranges to rot

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int ir = q.front().first;
                int jc = q.front().second; q.pop();
                for (int i = 0; i < 4; i++) {
                    int ni = ir + row[i], nj = jc + col[i];
                    if (valid(ni, nj) && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        q.push({ni, nj});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        return fresh == 0 ? ans : -1;
    }
};
