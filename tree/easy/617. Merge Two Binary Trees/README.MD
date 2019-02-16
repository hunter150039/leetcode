### 目录
#### 思路
用递归简便，以第一棵树为基础，如果有子树，二没字数保持原状退出，如果无子树，二有，换成二的分支，如果都有子树根节点相加。    
可以新建节点不新建节点，可以一个函数或者两个函数

---
 
#### 解法1
新建一棵树。

```  
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return NULL;
        if (!t1 || !t2) return t1? t1 : t2;
        TreeNode* node = new TreeNode(t1->val+t2->val);
            node->left = mergeTrees(t1->left, t2->left);
            node->right = mergeTrees(t1->right, t2->right);
        return node; 
    }
};
```  

#### 方法2  
使用原来的数     

```    
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        t1->val = t1->val + t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1; 
    }
};
```  

#### 方法3 
两个函数，但其实可以统一为一个

```  
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        preorder(t1, t2);
        
        return t1;
    }
    
    void preorder(TreeNode *&t1, TreeNode *&t2)
    {
        if(!t1){
            t1 = t2;
            return;
        } 
        if(!t2){
            return;
        }
        
        t1->val += t2->val;
        
        preorder(t1->right, t2->right);
        preorder(t1->left, t2->left);
    }
};
```

 




