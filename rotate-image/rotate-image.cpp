class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int ln = matrix.size();
        for(int i=0;i<ln;i++){
            for(int j=0;j<ln/2;j++){
                int temp;
                temp = matrix[j][i];
                matrix[j][i] = matrix[ln-j-1][i];
                matrix[ln-j-1][i] = temp;
            }
        }
        
        for(int i=0;i<ln;i++){
            for(int j=0;j<i;j++){
                    // cout << i << ',' << j <<endl;
                    int temp1;
                    temp1 = matrix[i][j];
                    // cout << matrix[i][j] << matrix[j][i]<<endl;
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp1;
            }
        }
        // for(int l=0;l<ln;l++){
        //     for(int m=0;m<ln;m++){
        //         // cout << "nj";
        //         // if(l!=m){
        //         //     int temp1;
        //         //     temp1 = matrix[l][m];
        //         //     matrix[l][m] = matrix[m][l];
        //         //     matrix[m][l] = temp1;
        //         // }        
        //     }
        // }
    }
};