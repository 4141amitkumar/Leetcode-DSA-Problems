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
public:
    void insert(TreeNode* root,int val){
        if(root==NULL) root = new TreeNode(val);
        if(root->val>val){
            if(root->left==NULL){
                root->left = new TreeNode(val);
            }
            else insert(root->left,val);
        }
        else{
            if(root->right==NULL){
                root->right = new TreeNode(val);
            }
            else insert(root->right,val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(root,val);
        if(root==NULL) root = new TreeNode(val);
        return root;
    }
};