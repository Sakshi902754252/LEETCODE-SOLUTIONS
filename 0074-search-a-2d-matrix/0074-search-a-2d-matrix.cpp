class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i =0; i< row; i++){
            if(target == matrix[i][0]){
                return true;
            }
            if(target > matrix[i][0]){
                int j = 0;
                while(j < col){
                    if(target == matrix[i][j]){
                        return true;
                    }
                    j++;
                }
            }else{
                break;
            }
        }
        return false;

        
    }
};