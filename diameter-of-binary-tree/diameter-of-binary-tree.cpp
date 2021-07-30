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

// class Solution {
// public:
//     int findHeight(TreeNode* root){
//         if(root==NULL) return 0;
//         return 1+max(findHeight(root->left),findHeight(root->right));
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL) return 0;
//         int dia= findHeight(root->left) + findHeight(root->right);
//         return max(max(dia,diameterOfBinaryTree(root->left)),diameterOfBinaryTree(root->right));   
//     }
// };


class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int ls = height(root->left);
        int rs = height(root->right);
        return max(ls,rs)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        int op1 = lh+rh;
        int op2 = diameterOfBinaryTree(root->left);
        int op3 = diameterOfBinaryTree(root->right);
        return max(max(op1,op2),op3);
    }
};