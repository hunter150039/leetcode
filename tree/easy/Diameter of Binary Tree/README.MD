### 目录：二叉树的直径
#### 思路
如果直径过根节点，结果是根节点左右两棵子树最大深度之和，如果不过根节点，结果是某棵子树的直径。  
这个在求树的高度的基础上更进一步，结合后序遍历。  
在二叉树的后序遍历中干了两件事，一是判断树的直径，二是记录树的深度，两个变量一个返回，一个引用。

---
 
#### 解法1
见思路。

```  
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
```  

#### 解法2  
另一个角度看问题 采用分治和递归的思想：根节点为root的二叉树的直径 = max(root-left的直径，root->right的直径，root->left的最大深度+root->right的最大深度+1)     

```    
int diameterOfBinaryTree(TreeNode* root) 
{
    if(root == nullptr)
        return 0;
    int d_l=diameterOfBinaryTree(root->left);
    int d_r = diameterOfBinaryTree(root->right);
    int height_l=getHeight(root->left);
    int height_r=getHeight(root->right);

    int tmp1=d_l > d_r ? d_l :d_r;
    int tmp2=height_l+height_r+1;
    return tmp1>tmp2 ? tmp1 :tmp2; 
}
// 获得二叉树的最大深度
int Solution::getHeight(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    int h_l=getHeight(root->left);
    int h_r=getHeight(root->right);
    return ((h_l > h_r) ? h_l :h_r)+1;
}
};
```  


 




