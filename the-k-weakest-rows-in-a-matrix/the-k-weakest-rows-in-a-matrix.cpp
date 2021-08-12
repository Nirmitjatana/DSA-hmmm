class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        typedef pair<int,int> node;
        priority_queue<node,vector<node>,greater<node>> pq;
        for(int i=0;i<mat.size();i++){
            int count = 0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    break;
                }
                else{
                    count++;    
                }
            }
            // cout << count << i <<endl;
            pq.push({count,i});
        }
        for(int i=0;i<k;i++){
            pair ans = pq.top();
            int idx = ans.second;
            pq.pop();
            result.push_back(idx);
        }
        return result;
    }
};