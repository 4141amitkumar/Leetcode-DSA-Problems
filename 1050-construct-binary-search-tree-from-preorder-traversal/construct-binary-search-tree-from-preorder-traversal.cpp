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
    TreeNode* build(vector<int>& preorder, int prelo, int prehi, vector<int>& inorder, int inlo, int inhi){
        if(prelo>prehi) return NULL;
        TreeNode* root=new TreeNode(preorder[prelo]);   //for the root node
        if(prelo==prehi) return root;
        int i = inlo;
        while(i<=inhi){  //search that root node in inorder
        if(inorder[i]==preorder[prelo]) break;
        i++;
        }
        int leftCount = i-inlo;
        int rightCount = inhi-i;
        root->left = build(preorder, prelo+1, prelo+leftCount, inorder, inlo, i-1);
        root->right = build(preorder, prelo+leftCount+1, prehi, inorder, i+1, inhi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        return build(preorder,0,n-1,inorder,0,n-1);
    }
};