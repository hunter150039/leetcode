### 目录：二叉树的直径
#### 思路
笨办法，先求出所有结点值之和，然后开始中序遍历数组，同时用变量sum来记录累加和，根据上面分析的规律来更新所有的数组。   
好办法，用后->中->左的办法递归，就是从大到小排列，这样可以得到先序遍历的逆序。

---
 
#### 解法1
见思路。

```  
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
```  

#### 解法2  
没有额外函数的方法，全局变量。思考是不是可不可以不用辅助函数   
[一个函数](https://leetcode.com/problems/convert-bst-to-greater-tree/discuss/100516/Java-Three-O(n)-Methods%3A-Recursive-Iterative-and-Morris-Traversal)  
      

```    
int sum = 0;
public TreeNode convertBST(TreeNode root) {
        if (root == null) return null;
        convertBST(root.right);
        root.val += sum;
        sum = root.val;
        convertBST(root.left);
        return root;
    }
```  


 




