class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        if(row==1 || column==1){
            return true;
        }
        vector<int> a=matrix[0];
        for(int i=1;i<row;i++){
            for(int j=1;j<column;j++){
                if(matrix[i][j]!=a[j-1]){
                    return false;
                }
            }
            a = matrix[i];
        }
        return true;
    }
};
