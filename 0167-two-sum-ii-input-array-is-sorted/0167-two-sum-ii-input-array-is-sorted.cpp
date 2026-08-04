class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans(2);
        int i=0;
        int j=numbers.size()-1;
        while(i<j){
            int a=numbers[i];
            int b=numbers[j];

            if(a+b==target){
                ans[0]=i+1;
                ans[1]=j+1;
                break;
            }
            else if(a+b > target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};