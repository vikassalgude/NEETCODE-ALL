class Solution {
public:
    int r,c;
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    bool valid(int row1,int col1){
        return(row1>=0&&row1<r&&col1>=0&&col1<c);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        r=grid.size();
        c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        // int 
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                if(valid(i+row[k],j+col[k])&&grid[i+row[k]] [j+col[k]]==INT_MAX){
                   grid[i+row[k]] [j+col[k]]=grid[i][j]+1;
                   q.push({i+row[k],j+col[k]});
                }
            }
        }
        


    }
};
