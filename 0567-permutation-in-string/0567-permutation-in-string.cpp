class Solution {
public:
    bool checkInclusion(string s1, string s2) {;
        if(s1.length() > s2.length()) return false;
        int windowsize=s1.length();

        vector<int>hash1(26,0);
        
        for(int i=0;i<s1.length();i++){
            hash1[s1[i]-'a']++;
        }

        vector<int>hash2(26,0);
        for(int i=0;i<windowsize;i++){
            hash2[s2[i]-'a']++;
        }


        int i=0;
        int j=windowsize-1;
        int n=s2.length();
        
        while(j<n){           
            int flag=true;
            for(int k=0;k<26;k++){
                    if(hash2[k]!=hash1[k]){
                        if(j==n-1){
                            return false;
                        }
                        hash2[s2[i]-'a']--;
                        hash2[s2[j+1]-'a']++;
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