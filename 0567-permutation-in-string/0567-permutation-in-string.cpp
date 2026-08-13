class Solution {
public:
    bool checkInclusion(string s1, string s2) {;
        
        int windowsize=s1.length();

        vector<int>hash1(26,0);
        for(int i=0;i<s1.length();i++){
            hash1[s1[i]-'a']++;
        }


        int i=0;
        int j=windowsize-1;
        int n=s2.length();
        
        while(j<n){
           vector<int>hash2(hash1);
           
           for(int k=i;k<=j;k++){
            hash2[s2[k]-'a']--;
           }
            int flag=true;
           for(int k=0;k<26;k++){
                if(hash2[k]!=0){
                    i++;
                    j++;
                    flag=false;
                    break;
                }
           }

           if(flag==true){
            return true;
           }

           
        }
        return false;

        

    }
};