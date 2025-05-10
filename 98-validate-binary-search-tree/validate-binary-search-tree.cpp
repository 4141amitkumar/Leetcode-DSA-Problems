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
    //Brute Force
    void maxi(TreeNode* root,long& maximum){
        if(root==NULL) return;
        maximum=max((long)root->val,maximum);
        maxi(root->left,maximum);
        maxi(root->right,maximum);
    }
    void mini(TreeNode* root,long& minimum){
        if(root==NULL) return;
        minimum=min((long)root->val,minimum);
        mini(root->left,minimum);
        mini(root->right,minimum);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        long maxii=LONG_MIN;
        maxi(root->left,maxii);
        long minii=LONG_MAX;
        mini(root->right,minii);
        if(root->val<=maxii) return false;
        if(root->val>=minii) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};