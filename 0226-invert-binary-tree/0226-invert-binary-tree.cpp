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
    void solve(TreeNode *node){
        if(node==NULL){
            return;
        }
        TreeNode *temp=node->left;
        node->left=node->right;
        node->right=temp;
        solve(node->left);
        solve(node->right);

    }
public:
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};