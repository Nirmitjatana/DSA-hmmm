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
//     TreeNode* insertInBST(TreeNode* root, int data){
//         if(root == NULL){
//             return new TreeNode(data);
//         }
//         if(data <= root->val){
//             root->left = insertInBST(root->left, data);
//         }
//         else{
//             root->right = insertInBST(root->right, data);
//         }
//         return root;
//     }
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         TreeNode* root = NULL;
//         // for(int i=0;i<nums.size();i++){
//         int mid = nums.size()/2;
//         int mid1 = mid;
//         while(mid--){
//             root = insertInBST(root,mid);    
//         }
        
//         // root = insertInBST(root,nums[i]);
//         // }
//         return root;
//     }
    
TreeNode* solve(vector<int> &nums ,int low,int high){
    
    if(low > high)
        return NULL;
    int mid = (low + high )/2;
    
    TreeNode* root = new TreeNode(nums[mid]);
    
    root -> left = solve(nums,low,mid - 1);
    root -> right = solve(nums,mid + 1,high);
    
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int mid = 0;
    // sort(nums.begin(),nums.end());
    
    return solve(nums,low,high);
    
}
};