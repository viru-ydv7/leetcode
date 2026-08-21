class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int l=1;
        int n=piles.size();
        int r=piles[n-1];
        int ans=INT_MAX;

        while(l<r){
            int mid=l+(r-l)/2;
            int time=0;

            // check how many takes the mid takes:
            for(int i=0;i<piles.size();i++){
                if(time>h){break;}
                if(piles[i]<=mid){
                    time++;
                }
                else{
                    int total=ceil((double)piles[i]/mid);
                    time+=total;
                }
            }

            if(time>h){
                l=mid+1;
            }
            else{
                ans=min(ans,mid);
                r=mid;
            }
        }

        if(l==r){
            return l;
        }
        return ans;
    }
};