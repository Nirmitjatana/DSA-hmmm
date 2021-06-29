class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(); // number of rows
        int n = matrix[0].size();// number of columns
        
        
        
        int i=0; int j=n-1; // starting from the rightmost top element
        
        while(i<m && j>=0)
        {
            if(target>matrix[i][j])i++; // next row
            
            else if(target<matrix[i][j])j--; // previous column
            
            else if(target==matrix[i][j]) return true; //  element found
        }
        
        return false;
        
    }
};