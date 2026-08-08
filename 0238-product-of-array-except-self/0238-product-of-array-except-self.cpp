class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int left=1;
        int right=1;
        for(int i=0;i<nums.size();i++){
            mp[i].push_back(left);
            left=left*nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            mp[i].push_back(right);
            right=right*nums[i];
        }

        vector<int>ans(nums.size());
        for(auto it:mp){
            ans[it.first]=it.second[0]*it.second[1];
        }
        return ans;
    }
};