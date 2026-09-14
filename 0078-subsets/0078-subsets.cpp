class Solution {
private:
    void backtrack(int index,int n, vector<vector<int>>&ans , vector<int>&temp,vector<int>& nums){
        if(index==n){
            ans.push_back(temp);
            return;
        }

        int number=nums[index];
        temp.push_back(number);
        index=index+1;
        backtrack(index,n,ans,temp,nums);
        temp.pop_back();
        backtrack(index,n,ans,temp,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        backtrack(index,n,ans,temp,nums);
        return ans;
    }
};