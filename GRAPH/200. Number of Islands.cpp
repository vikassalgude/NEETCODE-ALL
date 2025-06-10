class Solution {
public:
    bool valid(int i,int j){
        return (i>=0&&i<r&&j>=0&&j<c);
    }
    int r;int c;
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        r=grid.size();
        c=grid[0].size();
        queue<pair<int,int>>q;
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        int a=q.front().first;
                        int b=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            if(valid(a+row[k],b+col[k])&&grid[a+row[k]][b+col[k]]=='1'){
                                q.push({a+row[k],b+col[k]});
                                grid[a+row[k]][b+col[k]]='0';
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};
