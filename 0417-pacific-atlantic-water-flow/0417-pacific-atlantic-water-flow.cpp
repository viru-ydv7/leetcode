class Solution {
private:
    void bfs(int i,int j,vector<vector<int>>&ocean,vector<pair<int,int>>directions,vector<vector<int>>& heights,int r , int c){
        if(ocean[i][j]==1){
            return;
        }
        ocean[i][j]=1;
        for(auto it:directions){
            int rr=it.first;
            int cc=it.second;
            int newrow=i+rr;
            int newcol=j+cc;
            
            if(newrow>=r || newrow<0 || newcol >=c || newcol <0){
                continue;
            }
            else{
                if(heights[newrow][newcol] >= heights[i][j]){
                    bfs(newrow,newcol,ocean,directions,heights,r,c);
                }
                
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<int>>pacific(r,vector<int>(c,0));
        vector<vector<int>>atlantic(r,vector<int>(c,0));
        vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
        // pacific row
        for(int i=0;i<c;i++){
            // row=0;col=1;
            bfs(0,i,pacific,directions,heights,r,c);

        }
        // pacific col
        for(int i=0;i<r;i++){
            // row=i;col=0;
            bfs(i,0,pacific,directions,heights,r,c);

        }

        //atlantic row
        for(int i=0;i<c;i++){
            // row=0;col=1;
            bfs(r-1,i,atlantic,directions,heights,r,c);

        }
        // atlantic col
        for(int i=0;i<r;i++){
            // row=i;col=0;
            bfs(i,c-1,atlantic,directions,heights,r,c);

        }
        vector<vector<int>>ans;
        for(int i=0;i<r;i++){
            vector<int>a;
            for(int j=0;j<c;j++){
                if(pacific[i][j]==1){
                    if(pacific[i][j]==atlantic[i][j]){
                        a.push_back(i);
                        a.push_back(j);
                        ans.push_back(a);
                        a.pop_back();
                        a.pop_back();
                    }
                }
            }
        }

        return ans;

    }
};