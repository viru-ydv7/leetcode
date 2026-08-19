class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int right=r*c;
        int left=0;
        while(left<right){
            int mid=left+(right-left)/2;
            int row=mid/c;
            int col=mid%c;

            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col] > target){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }

        return false;
    }
};