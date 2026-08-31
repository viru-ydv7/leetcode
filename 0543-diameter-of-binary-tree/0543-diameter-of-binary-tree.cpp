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
    int solve(TreeNode *node,int &ans,int &finalans){
        if(node==NULL){
            return 0;
        }
        int l=solve(node->left,ans,finalans);
        int r=solve(node->right,ans,finalans);
        int final=l+r;
        finalans=max(finalans,final);
        return max(l,r)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int finalans=0;
        ans=solve(root,ans,finalans);
        return finalans;
    }
};