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
        int l=solve(node->left,ans);
        int r=solve(node->right,ans);
        ans=max(l,r)+1;
        return ans;
    }
public:
    int maxDepth(TreeNode* root) {
       int ans=0;
       ans=solve(root,ans);
       return ans;

    }
};