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
    bool solve(TreeNode *p,TreeNode *q,bool ans){
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL){
            return false;
        }
        if(q==NULL){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        ans=solve(p->left,q->left,ans);
        if(ans==false){
            return false;
        }
        ans=solve(p->right,q->right,ans);
        if(ans==false){
            return false;
        }
        return true;

        
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*>q;
        q.push(root);
        bool ans=false;
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node->val==subRoot->val){
                ans=solve(node,subRoot,ans);
                if(ans==true){
                    return true;
                }
               
            }  
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }          
        }

        if(ans==false){
            return false;
        }
        return true;
    }
};