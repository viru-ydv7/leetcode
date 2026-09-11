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
    void dfs(TreeNode *node,int &ans,int maxi){
        if(node==NULL){
            return;
        }
        if(node->val>=maxi){
            ans++;
        }
        int newMax = max(maxi , node->val);
        if(node->left){
            dfs(node->left,ans,newMax);
        }
        if(node->right){
            dfs(node->right,ans,newMax);
        }
        
    }
public:
    int goodNodes(TreeNode* root) {
        int ans=0;
        int maxi=root->val;
        dfs(root,ans,maxi);
        return ans;
    }
};