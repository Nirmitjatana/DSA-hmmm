class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // NlogN solution
        
        // int area = 0;
        // for(int i=0;i<height.size()-1;i++){
        //     for(int j=i+1;j<height.size();j++){
        //         int l = j-i;
        //         int b = height[i] < height[j] ? height[i] : height[j];
        //         if(l*b > area){
        //             area = l*b;
        //         }
        //     }
        // }
        // return area;
        
        // two pointer solution
        int max_area = 0;
        int l = 0;
        int r = height.size()-1;
        while(l<r){
            int area = (r-l)*min(height[l],height[r]);
            if(area > max_area){
                max_area = area;
            }
            if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return max_area;
    }
};