class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>hash(26,0);
        int l=0;
        int r=0;
        int len=0;
        int ans=0;
        int maxfreq=0;
        int n=s.length();
        while(r<n){
            hash[s[r]-'A']+=1;
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            len=r-l+1;

            if(len-maxfreq > k){
                while(len-maxfreq > k){
                    hash[s[l]-'A']--;
                    l++;
                    len--;
                }
            }
            ans=max(len,ans);
            r++;
            
           
           

        }
        return ans;
    }
};