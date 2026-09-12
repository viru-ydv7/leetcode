class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            int dist=((x*x)+(y*y));
            q.push({dist,i});
        }
        vector<vector<int>>ans;
        int p=0;
        while(p<k){
            auto it=q.top();
            q.pop();
            int i=it.second;
            ans.push_back(points[i]);
            p++;
        }
        return ans;
    }
};