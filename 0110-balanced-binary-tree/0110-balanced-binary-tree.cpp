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
    int solve(TreeNode *node,int &h){
        if(node==NULL){
            return 0;
        }
        int l=solve(node->left,h);
        int r=solve(node->right,h);
        if(l==-1 || r==-1){
            return -1;
        }
        if(abs(l-r)>1){
            return -1;
        }
        h=max(l,r)+1;
        return h;        
    }
public:
    bool isBalanced(TreeNode* root) {
        int h=0;
        int ans=solve(root,h);
        if(ans==-1){
            return false;
        }
        return true;
    }
};