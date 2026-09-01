/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* solve(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node==NULL){
            return NULL;
        }
        if(node==p || node==q){
            return node;
        }
        TreeNode *l=solve(node->left,p,q);
        TreeNode *r=solve(node->right,p,q);

        if(l==NULL && r==NULL){
            return NULL;
        }
        if(l==NULL){
            return r;
        }
        if(r==NULL){
            return l;
        }
        return node;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *answer;
        answer=solve(root,p,q);
        return answer;
    }
};