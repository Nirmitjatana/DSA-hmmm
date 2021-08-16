// 0 0 1 1 1 2 2 3 3 4
// i   j

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = 0;
        int no = 0;
        if(nums.size() == 1 ||nums.size() == 0){
            return nums.size();
        }
        for(int curr=1;curr<nums.size();curr++){
            if(nums[curr]!=nums[prev]){
                prev++;
                nums[prev] = nums[curr];    
                no++;
            }
        }
        return no+1;
    }
};