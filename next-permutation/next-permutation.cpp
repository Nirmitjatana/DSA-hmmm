class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j; 
        int n=nums.size();
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                break;
        }
        if(i<0)  //if no permutation can be made
            reverse(nums.begin(),nums.end());
        else
        {
            for(j=n-1;j>i;j--)
            {
                if(nums[i]<nums[j])
                    break;
            }
        swap(nums[j],nums[i]);
        reverse(nums.begin()+i+1,nums.end());
        }
    }
};