class Solution {
public:
    int maxi = 0;
    int height(TreeNode* root) {
        if (!root) return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);
        maxi = max(maxi, leftH + rightH);
        return 1 + max(leftH, rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxi;
    }
};
