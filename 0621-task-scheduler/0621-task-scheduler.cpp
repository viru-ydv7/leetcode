class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>>q;
        unordered_map<char,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        for(auto it:mp){
            q.push({it.second,it.first});
        }
        int time=0;
        while(!q.empty()){
            vector<pair<int,char>>used;
            for(int i=0;i<n+1;i++)
            {
                
                if(!q.empty()){
                    auto it=q.top();
                    q.pop();
                    int freq=it.first;
                    char ch=it.second;

                    freq--;
                    // cpu executing the task
                    time++;
                    if(freq>0){
                        used.push_back({freq,ch});
                    }
                }
                else{
                    //idle;.
                    if(!used.empty()){
                        time++;
                    }
                }
            }
            for(auto it:used){
                q.push(it);
            }


        }

        return time;
    }
};