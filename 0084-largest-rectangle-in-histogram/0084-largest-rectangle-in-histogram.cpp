class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        st.push(-1);
        vector<int>a(heights.size());
        int ans=0;
        for(int i=0;i<heights.size();i++){
            while(st.top()!=-1 && heights[i] <= heights[st.top()] ){
                
                int h=heights[st.top()];
                st.pop();
                int left=st.top();
                int b=i-left-1;
                int area=h*b;
                ans=max(area,ans);            
            }

            st.push(i);
        }

        while(st.top()!=-1){
            int r=heights.size();
            int h=heights[st.top()];
            st.pop();
            int left=st.top();
            int b=r-left-1;
            int area=h*b;
            ans=max(area,ans);
            
        }
        

        return ans;
    }
};