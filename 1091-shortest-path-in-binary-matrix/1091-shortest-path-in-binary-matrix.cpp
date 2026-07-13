class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<pair<int, int>> directions = {
            {-1, 0},   // up
            {-1, 1},   // up-right
            {0, 1},    // right
            {1, 1},    // down-right
            {1, 0},    // down
            {1, -1},   // down-left
            {0, -1},   // left
            {-1, -1}   // up-left
        };
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        dist[0][0]=1;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;

            for(auto &e:directions)
            {
                int r=e.first;
                int c=e.second;

                if (row + r < 0 or row + r >= n or col + c < 0 or col + c >= n)
                {
                    continue;
                }

                if(grid[row+r][col+c]==1)
                {
                    continue;
                }

               int d =dist[row][col]+1;
               if(d<dist[row+r][col+c])
               {
                dist[row+r][col+c]=d;
                q.push({row+r,col+c});
               }

            }
            
        }
        
        int ans= dist[n-1][n-1];
        if(ans==INT_MAX){
            return -1;
        }
       return ans;
    }
};

