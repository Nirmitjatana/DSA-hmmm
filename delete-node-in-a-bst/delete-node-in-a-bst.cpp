class Solution {
public:
     TreeNode*callcheck(TreeNode*root){
       TreeNode*temp=root;
          while(temp->left!=nullptr){
           temp=temp->left;
          }
       return temp;
     }
      TreeNode* deleteNode(TreeNode* root, int key) {
         if(root==nullptr) return nullptr;
         if(root->val==key){
           
            if(root->left && root->right){
                 TreeNode*temp=callcheck(root->right);
                 root->val=temp->val;
             // cout<<temp->val;
               root->right=deleteNode(root->right,temp->val);
                 return root;
            }
             if(root->left ){
                   return root->left;
             }
           else if(root->right) return root->right;
           return nullptr;
         
         }
        if(root->val>key) root->left=deleteNode(root->left,key);
         else if(root->val<key) root->right=deleteNode(root->right,key);
        
           return root;
      }
};
