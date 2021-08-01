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
    int traversal(TreeNode* root, int &sum){
        if (root == NULL) return 0;
        if(root->left){
            TreeNode* next = root->left;
            if(!next->left && !next->right){
                sum += next->val;
                // cout << sum << endl;
            }    
        }
        traversal(root->left,sum);
        traversal(root->right,sum);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = 0;
        return traversal(root,sum);
    }
};