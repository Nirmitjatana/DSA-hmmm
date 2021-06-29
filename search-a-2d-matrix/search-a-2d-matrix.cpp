class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ln=matrix.size();
        int st=0;
        for(int i=0;i<ln;i++){
            if(target>=matrix[i][0]){
                st=i;
                // if(i>0){
                //     st=i-1;    
                // } 
            } 
        }
        int width = matrix[0].size();
        bool ans = false;
        for(int i=0;i<width;i++){
            if(matrix[st][i] == target){
                ans = true;
            }
        }
        return ans;
    }
};