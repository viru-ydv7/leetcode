class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &e:times){
            adj[e[0]].push_back({e[1],e[2]});
        }

        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        dist[0]=0;
        // dijkstra algo
        queue<pair<int,int>>q;
        q.push({k,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first;
            int distance = it.second;

            for(int i=0;i<adj[node].size();i++){
                auto n=adj[node][i];
                int neigbour=n.first;
                int d=n.second;

                int newdistance = distance+d;
                if(newdistance < dist[neigbour]){
                    dist[neigbour]=newdistance;
                    q.push({neigbour,newdistance});
                }
            }
        }
            int ans=INT_MIN;
            for(int i=0;i<n+1;i++){
                if(ans<dist[i]){
                    ans=dist[i];
                }
            }
            if(ans==INT_MAX){
                return -1;
            }
            return ans;


    }
};