class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int number = nums[i];
            int diff = target-number;
            if(mp.find(diff)==mp.end()){
                mp[number]=i;
            }
            else{
                ans.push_back(mp[diff]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};