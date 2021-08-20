class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n];
        int right[n];
        //max variables
        int left_max = height[0];
        int right_max = height[n-1];
        //left max calc
        for(int i=0;i<n;i++){
            left_max = max(left_max,height[i]);
            left[i] = left_max;
        }
        //right max calc
        for(int i=n-1;i>=0;i--){
            right_max = max(right_max,height[i]);
            right[i] = right_max;
        }
        //calc water
        int ans = 0;
        for(int i=0;i<n;i++){
            // cout << left[i] << " " << right[i] << endl;
            int len = min(left[i],right[i]);
            int ad = len-height[i];
            ans+=ad;
        }
        return ans;
    }
};