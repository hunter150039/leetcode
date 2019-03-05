### 目录：节点是否是堂兄
#### 思路
<font color=red>求深度+父亲</font>  
是判断节点层数的扩展，节点所在层用BFS和DFS均可判断.  
通过树的遍历，分别找到结点 x 和 y 的深度和对应的父亲。
本题也可用BFS和DFS

#### 时间复杂度
每个结点最多被访问常数次，故时间复杂度为 O(n)。
#### 空间复杂度
深度优先遍历需要额外 O(h)的栈空间，宽度优先遍历需要 O(n) 实际上没这么大。 

---
 
#### 解法1
DFS。

```  
class Solution {
public:
    int xLevel,xfather,yLevel,yfather;    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,0,x,y,0);
        if(xLevel==yLevel && xfather!=yfather){
            return true;
        }   
        return false;
    }
    
    void dfs(TreeNode* root,int level, int x, int y,int father){
        if(!root){
            return;
        }
        if(root->val==x){
            xLevel=level;
            xfather = father;
        }
        if(root->val==y){
            yLevel=level;
            yfather = father;
        }
        dfs(root->left,level+1,x,y,root->val);
        dfs(root->right,level+1,x,y,root->val);        
    }
};
```  

#### 解法2  
BFS 
主要是获取节点所在深度，甚至是当前层的所有节点，参考问题：。  
       

```    
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
```  


 




