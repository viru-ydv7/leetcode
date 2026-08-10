class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int l=0;
        int r=1;
        int n=s.length();
        if(n==0){
            return 0;
        }
        int len=1;
        int ans=1;
        st.insert(s[l]);
        while(r<n){
            // if valid
            if(!st.count(s[r])){
                len++;
                st.insert(s[r]);
                r++;
                ans=max(ans,len);
            }
            else{
                while(st.count(s[r])){
                   st.erase(s[l]);
                   len--;
                   l++;
                }

            }
        }

        return ans;
    }
};