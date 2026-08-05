class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<=nums.size()-3){
            if (i > 0 && nums[i] == nums[i-1]){
                i++;
                continue;
            };
            int j=nums.size()-1;
            int k=i+1;
            
            while(k<j){
                
                
                int a=nums[i];
                int b=nums[j];
                int c=nums[k];

                int sum=a+b+c;
                if(sum==0){
                    ans.push_back({a,c,b});
                    k++;
                    j--;
                    while( k<j && nums[k]==nums[k-1]){
                        k++;
                        
                    }
                    while(k < j && nums[j]==nums[j+1]){
                        j--;
                        
                    }
                }
                else if(sum < 0){
                    k++;
                }
                else{
                    j--;
                }
            }
            i++;
        }


        return ans;
    }
};