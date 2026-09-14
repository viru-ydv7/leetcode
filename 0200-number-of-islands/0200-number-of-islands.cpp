class Solution {
private:
    void bfs(int i , int j ,int &island,vector<vector<int>>&visited,vector<pair<int,int>>directions,vector<vector<char>>& grid ,int r , int c){
        if(visited[i][j]!=0){
            return;
        }
        if(grid[i][j]=='0'){
            return;
        }
        visited[i][j]=1;
        for(auto it:directions){
            int row=it.first;
            int col=it.second;

            if(i+row >=r || i+row <0 || j+col >=c || j+col <0){
                continue;
            }
            else{
                bfs(i+row,j+col,island,visited,directions,grid,r,c);
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int island=0;
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>visited(r,vector<int>(c));
        vector<pair<int,int>>directions={{0,-1},{0,1},{1,0},{-1,0}};


        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' && visited[i][j]!=1){
                    bfs(i,j,island,visited,directions,grid,r,c);
                    island++;
                }
            }
        }
        
        return island;
        
    }
};