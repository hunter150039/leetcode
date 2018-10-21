class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        if(row==1 || column==1){
            return true;
        }
        for(int k=0;k<column;k++){
            int i=0,j=k;
            while(i+1<row && j+1<column){
                if(matrix[i][j]!=matrix[i+1][j+1])
                    return false;
                i++;j++;
            }
        }
        for(int k=1;k<row;k++){
            int i=k,j=0;
            while(i+1<row && j+1<column){
                if(matrix[i][j]!=matrix[i+1][j+1])
                    return false;
                i++;j++;
            }
        }
        return true;
    }
};
