class Solution {
private:
    bool dfs(int node , vector<int>&visited , vector<int>&path , vector<vector<int>> &adj){
        visited[node]=1;
        path[node]=1;

        for(int i=0;i<adj[node].size();i++){
            int neighbour = adj[node][i];
            if(visited[neighbour]){
                if(path[neighbour]){
                    return true;
                }
            }
            else{
                if(dfs(neighbour,visited,path,adj)==true){
                    return true;
                }
            }
        }
        path[node]=0;
        return false;

    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>path(numCourses,0);
        vector<int>visited(numCourses,0);
        for(auto &e:prerequisites){
            adj[e[1]].push_back(e[0]);
        }

        for(int i=0;i<numCourses;i++){
            if(visited[i]!=1){
                if(dfs(i,visited,path,adj)==true){
                    return false;
                }
            }
            
        }
        return true;
    }
};