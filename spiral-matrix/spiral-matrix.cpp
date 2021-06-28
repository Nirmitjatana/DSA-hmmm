class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int tl = 0; //hl
        int tr = matrix[0].size()-1; //hr
        int br = matrix.size()-1; //vd
        int bl = 0; //vt
        vector<int> ans;
        while(tl<=tr && bl<=br){
            for(int i=tl;i<=tr;i++){
            ans.push_back(matrix[bl][i]);
            // cout << matrix[tl][i];
            }
            bl++;
            if(bl>br){
                break;
            }
            for(int i=bl;i<=br;i++){
                ans.push_back(matrix[i][tr]);
            }
            tr--;
            if(tl>tr){
                break;
            }
            for(int i=tr;i>=tl;i--){
                ans.push_back(matrix[br][i]);
            }
            br--;
            if(bl>br){
                break;
            }
            // cout <<tl;
            for(int i=br;i>=bl;i--){
                // cout << i;
                ans.push_back(matrix[i][tl]);
            }
            // br++;
            tl++;
            if(tl>tr){
                break;
            }
        }
        return ans;
    }
};