class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int>ans(n,0);
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        for(int i=0;i<n;i++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
            q.push({0,i});
            vector<int>distt(n,INT_MAX);
            distt[i]=0;
            while(!q.empty()){
                auto it=q.top();
                q.pop();
                int distance=it.first;
                int node=it.second;

               

                for(int j=0;j<adj[node].size();j++){
                    auto n=adj[node][j];
                    int neigbour=n.first;
                    int weight=n.second;

                    int total=distance+weight;
                    if(total<=distanceThreshold && total < distt[neigbour]){
                        q.push({total,neigbour});
                        distt[neigbour]=total;

                    }
                }
            }

            for(int k=0;k<n;k++){
                if(distt[k]<=distanceThreshold && k!=i){
                    ans[i]++;
                }
            }
        }
        int minn=INT_MAX;
        for(int i=0;i<n;i++){
            if(ans[i]<minn){
                minn=ans[i];
            }
        }
        int answer=0;
        for(int i=0;i<n;i++){
            if(ans[i]==minn){
                answer=i;
            }
        }

        return answer;
    }
};