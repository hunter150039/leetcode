class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        int sum = 0;
        traversal(root,sum);
        return root;        
    }
    
    void traversal(TreeNode* root,int &sum){
        if(root ==NULL){
            return ;
        }
        traversal(root->right,sum);
        root->val+=sum;
        sum = root->val;
        traversal(root->left,sum);  
    }
};
