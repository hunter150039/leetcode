class Solution {
public:

    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> fatherlVec(101,0);
        vector<int> levalVec(101,0);
        queue<TreeNode*> que;
        que.push(root);
        fatherlVec[root->val] = -1;
        levalVec[root->val] = 0;        
        while(!empty(que)){
            TreeNode* tmp = que.front();
            if(tmp->left){
                que.push(tmp->left);
                fatherlVec[tmp->left->val] = tmp->val;
                levalVec[tmp->left->val] = levalVec[tmp->val]+1; 
            }
            if(tmp->right){
                que.push(tmp->right);
                fatherlVec[tmp->right->val] = tmp->val;
                levalVec[tmp->right->val] = levalVec[tmp->val]+1;  
            }
            que.pop();
        }
        if(levalVec[x]==levalVec[y] && fatherlVec[x]!=fatherlVec[y]){
            return true;
        }
        return false;
    }
}
