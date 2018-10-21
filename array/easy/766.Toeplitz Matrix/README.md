##我的思路
#### 方法1
假设内村不足，按照每次读入一行来操作，将这一行右移与下一行错位比较。
#### 方法2
可以直接将矩阵加载进内存，将矩阵按对角分成两部分遍历。   
在while循环变量处谢了BUG，忘了while中的变量改变也会改变for循环中的变量。  

---
##他人的思路
#### 方法1
我的方法2完全没必要将矩阵分成两部分，直接用当成一个矩阵，来比较右下元素与当前元素的差异。

```  
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != matrix[i-1][j-1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```  

#### 方法2  
和我的法1比较接近，随谈不是每次都来一行，但是代码风格比较好    

```  
class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    for(int i=0;i<matrix.size()-1;i++) {
      if (!compare(matrix[i],matrix[i+1])) return false;
    }
    return true;
  }

  bool compare(const vector<int>& v1, const vector<int>& v2, int start = 0) {
    //if (v1.size() != v2.size()) throw someException;
    for ( int i=start;i<v1.size()-1;i++) {
      if(v1[i]!=v2[i+1]) return false;
    }
    return true;
  }
  //比较两行可以用这种方式
  //m1.pop_back();
  //m2.erase(m2.begin());
};
```  

 



