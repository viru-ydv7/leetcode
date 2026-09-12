/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode *node,int &ans){
       
        if(node==NULL){
            return 0;
        }
      
        int a=solve(node->left,ans);
        if(a<0)a=0;

        int b=solve(node->right,ans);
        if(b<0)b=0;
        int sum=max(a,b)+node->val;
        int path=a+b+node->val;
        ans=max(path,ans);
        return sum;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int sum=solve(root,ans);
        return ans;
    }
};