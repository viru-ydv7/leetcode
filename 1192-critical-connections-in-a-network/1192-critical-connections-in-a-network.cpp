class Solution {
    int timer=1;
private:
    void dfs(int node , int parent , vector<int>&tin, vector<int>&low, vector<int>&visited, vector<vector<int>>&adj,vector<vector<int>>&bridges){
        visited[node]=1;
        tin[node]=low[node]=timer;
        timer++;
          for(auto it:adj[node]){
            if(it==parent){
                continue;
            }
            if(visited[it]!=1){
                dfs(it,node,tin,low,visited,adj,bridges);
                low[node]=min(low[it],low[node]);
                

                // checking if they are bridge;
                if(low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],tin[it]);
            }
          }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>tin(n);
        vector<int>low(n);
        vector<vector<int>>adj(n);
        vector<vector<int>>bridges;
        vector<int>visited(n,0);

        for(auto &e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0,-1,tin,low,visited,adj,bridges);
        return bridges;

        
    }
};