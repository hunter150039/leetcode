### 目录
#### 方法1
递归法。观察函数，输入根节点输出根节点，可以做到与子树相同的操作，所以不需要另起函数
#### 方法2
非递归，层次遍历     
可以用swap(temp->left, temp->right);  交换两个节点

---
 
#### 解法1
一个函数中，比较优美。

```  
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        TreeNode* ptemp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(ptemp);
        return root;
    }
};
```  

#### 方法2  
不在同一个函数中      

```    
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        invertSubTree(root);
        return root;
    }
    
    void invertSubTree(TreeNode* p){
        if(p==NULL){
            return;
        }

        invertSubTree(p->left);
        invertSubTree(p->right);
 
        TreeNode* ptmp;
        ptmp = p->left;
        p->left = p->right;
        p->right = ptmp;

        
    }
    
};
```  

#### 方法3 
非递归，用队列,类似层次遍历

```  
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root ==NULL){
            return NULL;
        }
        queue<TreeNode*> nodeque;
        TreeNode* nodetmp,*nodetmp2;
        nodeque.push(root);
        while(!nodeque.empty()){
            nodetmp = nodeque.front();
            if(nodetmp->left !=NULL){
                nodeque.push(nodetmp->left);
            }
            if(nodetmp->right !=NULL){
                nodeque.push(nodetmp->right);
            }
            
            nodetmp2 = nodetmp->left;
            nodetmp->left = nodetmp->right;
            nodetmp->right = nodetmp2;
                
            nodeque.pop();     
        }
        return root;
            
    }
};
```

 



