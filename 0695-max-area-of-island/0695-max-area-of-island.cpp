class Solution {
private:
    void bfs(int i , int j , int &area ,vector<vector<int>>&visited,vector<pair<int,int>>directions,vector<vector<int>>& grid, int r , int c ){
        if(visited[i][j]==1){
            return;
        }
        if(grid[i][j]==0){
            return;
        }
        visited[i][j]=1;
        area=area+1;
        for(auto it:directions){
            int row=it.first;
            int col=it.second;

            if(i+row >=r || i+row <0 || j+col >=c || j+col <0){
                continue;
            }
            else{
                bfs(i+row,j+col,area,visited,directions,grid,r,c);
            }
        }
        return;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>visited(r,vector<int>(c,0));
        vector<pair<int,int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
        int area=0;
        int answer=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(visited[i][j]!=1 && grid[i][j]==1){
                    bfs(i,j,area,visited,directions,grid,r,c);
                    answer=max(answer,area);
                    area=0;                  
                }
            }
        }

        return answer;
    }
};