class Solution {
public:
    void welp(vector<int>& nums, vector<vector<int>>& ans, int idx, int size){
        //Base case
        if(idx == size){
            // cout << "nj";
            ans.push_back(nums);
            return;
        }
        //recursive case
        for(int i=idx;i<size;i++){
            swap(nums[idx],nums[i]);
            welp(nums,ans,idx+1,size);
            //backtracking
            swap(nums[idx],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        welp(nums,ans,0,size);
        return ans;
    }
};




// class Solution {
//  public:
//   void help(vector<int> &nums, int begin, vector<vector<int>> &result) {
//       if (begin >= nums.size()) {
//           result.push_back(nums);
//           return;
//       }

//       for (int i = begin; i < nums.size(); i++) {
//           swap(nums[i], nums[begin]);
//           help(nums, begin + 1, result);
//           swap(nums[i], nums[begin]);
//       }
//   }

//   vector<vector<int>> permute(vector<int> &nums) {
//       vector<vector<int>> result;
//       help(nums, 0, result);
//       return result;
//   }
// };