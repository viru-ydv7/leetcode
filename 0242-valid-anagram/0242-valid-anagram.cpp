class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>a(26,0);
        vector<int>b(26,0);

        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            a[index]++;
        }
        for(int i=0;i<t.length();i++){
            int index=t[i]-'a';
            b[index]++;
        }

        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         vector<int>alpha(26,0);
//         int n=s.length();
//         int m=t.length();

//         if(n!=m){
//             return false;
//         }
//         for(int i=0;i<s.length();i++){
//             int index = s[i]-'a';
//             int index2 = t[i]-'a';

//             alpha[index]++;
//             alpha[index2]--;
//         }

//         for(int e:alpha){
//             if(e!=0){
//                 return false;
//             }
//         }
//         return true;
//     }
// };