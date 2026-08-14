class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        int result;
        for(int i=0;i<n;i++){
            string op=tokens[i];
            if(op=="+"){
               int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                result=n1+n2;
                st.push(result);
            }
            else if(op=="*"){
               int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                result=n1*n2;
                st.push(result);

            }
            else if(op=="/"){
               int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                result=n2/n1;
                st.push(result);
                
            }
            else if(op=="-"){
               int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                result=n2-n1;
                st.push(result);

            }
            else{
                int num=stoi(op);
                st.push(num);
            }

           
        }

         return st.top();
    }
};