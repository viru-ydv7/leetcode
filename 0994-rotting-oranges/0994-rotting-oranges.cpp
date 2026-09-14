class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>visited(r,vector<int>(c,0));
        vector<pair<int,int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
        queue<pair<int,int>>q;
        int t=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int k=q.size();
            bool flag=false;
            for(int i=0;i<k;i++){
                auto it=q.front();
                q.pop();
                int row=it.first;
                int col=it.second;
                for(auto d:directions){
                    int rr=d.first;
                    int cc=d.second;

                    if(rr+row >=r || rr+row<0 || cc+col >=c || cc+col <0){
                        continue;
                    }
                    else{
                        if(grid[rr+row][cc+col]==1 && visited[rr+row][cc+col]==0){
                            flag=true;
                            grid[rr+row][cc+col]=2;
                            q.push({rr+row,cc+col});
                            visited[rr+row][cc+col]=1;

                        }
                    }
                }

               
            }
            if(flag){
                    t++;
                }
                flag=false;
           
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return t;
    }
};