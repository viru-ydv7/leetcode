class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft=height[0];
        int maxRight=height[height.size()-1];
        int ans=0;
        // we choose the minimum of the two
        int i=0;
        int j=height.size()-1;
        
        while(i<=j){
            int minimumheight=min(maxLeft,maxRight);
            if(minimumheight==maxLeft){
                int water=minimumheight-height[i];
                if(water>0){
                    ans+=water;
                }
                maxLeft=max(maxLeft,height[i]);
                i++;
            }
            else{
                int water=minimumheight-height[j];
                if(water>0){
                    ans+=water;
                }
                maxRight=max(maxRight,height[j]);
                j--;
            }
            
        }

        return ans;
    }
};