class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ncol = matrix.size();   // number of col
        int nrow = matrix[0].size();  // number of rows

        bool first_row = false;
        bool first_col = false;
        // Check if first row and first column need to be set to 0
        for(int j =0; j< nrow; j++){
            if(matrix[0][j] == 0){
                first_row = true;
                break;
            }
        }

        for(int i =0; i< ncol;i++){
            if(matrix[i][0] == 0){
                first_col = true;
                break;
            }
        }
        // Use first row and first column to store information about other rows and columns
        for(int i = 1; i< ncol; i++){
            for(int j=1 ; j< nrow ;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
         // Set rows and columns to 0 based on information in first row and first column
        for (int i = 1; i < ncol; i++) {
            for (int j = 1; j < nrow; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (first_row) {
            for (int j = 0; j < nrow; j++) {
                matrix[0][j] = 0;
            }
        }
        if (first_col) {
            for (int i = 0; i < ncol; i++) {
                matrix[i][0] = 0;
            }
        }
        
    }
};