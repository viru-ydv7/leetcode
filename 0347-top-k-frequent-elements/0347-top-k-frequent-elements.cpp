class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto it:mp){
            int number=it.first;
            int frequency=it.second;
            v.push_back({frequency,number});
        }
        sort(v.begin(),v.end());
        int i=v.size()-1;
        while(k!=0){
            auto it=v[i];
            int num=it.second;
            ans.push_back(num);
            i--;
            k--;
        }

        return ans;
    }
};