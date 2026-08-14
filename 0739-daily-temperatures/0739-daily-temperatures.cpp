class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        int n=temperatures.size();
        vector<int>answer(n);
        for(int i=n-1;i>=0;i--){
            int flag=true;
            while(flag){
                if(st.empty()){
                    st.push({temperatures[i],i});
                    answer[i]=0;
                    break;
                }
                auto t=st.top();
                int top=t.first;
                int index=t.second;
                if(top>temperatures[i]){
                    answer[i]=index-i;
                    st.push({temperatures[i],i});
                    flag=false;
                }
                else{
                    st.pop();
                }
            }
        }

        return answer;
    }
};