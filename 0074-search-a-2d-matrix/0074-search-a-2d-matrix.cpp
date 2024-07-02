class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 1 && matrix[0].size() == 1) return target == matrix[0][0];
        if(matrix.size() == 1){
            for(int i=0; i<matrix[0].size(); i++){
                if(target == matrix[0][i])return true;
            }
            return false;
        }
        if(matrix[0].size() == 1){
            for(int i=0; i<matrix.size(); i++){
                if(target == matrix[i][0]) return true;
            }
            return false;
        }

        int i=0;
        int j=matrix[0].size()-1;

        int currow = 0;
        while(currow < matrix.size()){
            if(target == matrix[currow][i] || target == matrix[currow][j]) return true;
            else if(target > matrix[currow][i] && target < matrix[currow][j]){
                while(i<j && i<matrix[0].size()){
                    if(target == matrix[currow][i]) return true;
                    else i++;
                }
                return false;
            }
            else if(target > matrix[currow][j]){
                i=0;
                currow++;
            }
            else return false;
        }
        return false;
    }
};