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
    void dfs(TreeNode *node , vector<int>&ans){
        if(node==NULL){
            return;
        }
        dfs(node->left,ans);
        ans.push_back(node->val);
        dfs(node->right,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        int answer;
        dfs(root,ans);
        

        return ans[k-1];
    }
};