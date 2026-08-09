class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int ans=0;
        // if(nums.size()==1){
        //     return 1;
        // }
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);

        }

        for(auto i:st){
           if(st.count(i-1)){
                // this is not the start of the sequence , so we do nothing with this , the start will do itself
                ans=max(1,ans);
                continue;
           } 
           else{
                int current=i;
                int count=0;
                while(st.count(current)){
                    count++;
                    current=current+1;
                }
                ans=max(count,ans);
           }
        }
        return ans;
    }
};