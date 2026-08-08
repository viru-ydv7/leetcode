class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int>st;

        // checking rows
        for(auto it:board){
            for(auto ch:it){
                if(ch=='.'){
                    continue;
                }
                if(!st.count(ch)){
                    st.insert(ch);
                }
                else{
                    return false;
                }
            }
            st.clear();
        }
        st.clear();
        int rows=board.size();
        int cols=board[0].size();

        // checking cols
        for(int i=0;i<cols;i++){
            for(int j=0;j<rows;j++){
                char ch=board[j][i];
                if(ch=='.'){
                    continue;
                }
                if(!st.count(ch)){
                    st.insert(ch);
                }
                else{
                    return false;
                }
            }

            st.clear();
        }


        unordered_set<int>mp[9];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
               // we could create a 2d matrix , but here we'll directly convert the 2d->1d formula ( row*3+col);
               int r=i/3;
               int c=j/3;
               int box=r*3+c;
               if(board[i][j]=='.'){
                continue;
               }

               if(mp[box].count(board[i][j])){
                    return false;
               }
               else{
                mp[box].insert(board[i][j]);
               }
            }
        }

        return true;

    }
};