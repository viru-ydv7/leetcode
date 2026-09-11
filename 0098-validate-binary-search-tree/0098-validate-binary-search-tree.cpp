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
    void solve(TreeNode *node ,long long mini, long long maxi , bool &ans){
        if(node==NULL){
            return;
        }
        if(node->val <= mini || node->val >= maxi){
            ans=false;
            return;
        }

        solve(node->left,mini,node->val,ans);
        solve(node->right,node->val,maxi,ans);

    }
public:
    bool isValidBST(TreeNode* root) {
        bool ans=true;

        long long mini=LLONG_MIN;
        long long maxi=LLONG_MAX;
        solve(root,mini,maxi,ans);
        return ans;

    }
};