class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            int length=min(height[i],height[j]);
            int breadth=j-i;

            int area=length*breadth;
            ans=max(ans,area);

            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }

        }

        return ans;
    }
};