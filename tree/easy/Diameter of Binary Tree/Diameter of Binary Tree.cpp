class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root ==NULL){
            return NULL;
        }
        int diameter=0;
        treeLength(root,diameter);
        return diameter-1;
    }
    
    int treeLength(TreeNode* root,int &maxLength){
        if(root ==NULL){
            return 0;
        }    
        int letfLen = treeLength(root->left,maxLength);
        int rightLen = treeLength(root->right,maxLength);
        int totalLen = letfLen+rightLen+1;
        if(totalLen>maxLength){
            maxLength = totalLen;
        }
        return max(letfLen,rightLen)+1;
    }
    
};
