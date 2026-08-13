// class Solution {
// public:
//     bool isValid(string s) {
        
//         stack<char>st;
//         int n=s.length();
//         if(n==0){
//             return true;
//         }
        
//         for(int i=0;i<n;i++){
//             if(!st.empty()){            
//                 char t=st.top();
//                 if(t=='(' && s[i]==')'){
//                     st.pop();
//                 }
//                 else if(t=='{' && s[i]=='}'){
//                     st.pop();
//                 }
//                 else if(t=='[' && s[i]==']'){
//                     st.pop();
//                 }
//                 else{
//                     st.push(s[i]);
//                 }

//             }
//             else{
//                 st.push(s[i]);
//             }
//         }

//         if(st.empty()){
//             return true; 
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(st.empty()){
                    return false;
                }
                char t=st.top();
                if(t=='(' && s[i]==')'){
                    st.pop();
                }
                else if(t=='{' && s[i]=='}'){
                    st.pop();
                }
                else if(t=='[' && s[i]==']'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                st.push(s[i]);
            }
        }

        if(st.empty()){
            return true;
        }
        return false;
    }
};