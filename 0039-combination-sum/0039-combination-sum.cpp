class Solution {
private:
    void backtrack(int &t ,int index, vector<int>&temp,vector<vector<int>>&ans,vector<int>& candidates,int target){
        if(index==candidates.size() || t>target){
            return;
        }
        if(target==t){
            ans.push_back(temp);
            return;
        }
        int number=candidates[index];
        
        t=t+number;
        temp.push_back(number);
        backtrack(t,index,temp,ans,candidates,target);
        t=t-number;
        temp.pop_back();
        index=index+1;
        backtrack(t,index,temp,ans,candidates,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int t=0;
        int index=0;
        vector<int>temp;
        vector<vector<int>>ans;
        backtrack(t,index,temp,ans,candidates,target);

        return ans;

    }
};