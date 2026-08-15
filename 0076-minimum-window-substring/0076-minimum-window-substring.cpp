class Solution {
public:
    string minWindow(string s, string t) {
    
        int m=s.length();
        int answer=INT_MAX;
        int n=t.length();
        string anss="";
        int starting=INT_MAX;
        int ending=INT_MAX;
        vector<int>need(128,0);
        vector<int>window(128,0);
        int required=0;
        int formed=0;
        
        for(int i=0;i<n;i++){
            char ch=t[i];
            if(need[ch]==0){
                required++;
            }
            need[ch]++;
        }  
        int i=0;
        int j=0;
        while(j<m){
            char ch=s[j];
            int index=ch;
            window[index]++;
            if(window[index]==need[index]){
                formed++;
            }
            if(formed==required){
                while(formed==required){
                    if(j-i+1 < answer){
                        answer=j-i+1;
                       starting=i;
                       ending=j;
                    }
                    int id=s[i];
                    if(window[id]==need[id]){
                        formed--;
                    }
                    window[id]--;
                    i++;
                }
            }
           j++;
        }

        return answer == INT_MAX ? "" : s.substr(starting, answer);    
    }
};