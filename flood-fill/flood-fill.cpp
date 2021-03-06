class Solution {
public:
    
    void nj(vector<vector<int>>& image, int sr, int sc, int color, int newColor){
        if(image[sr][sc] == color){
            image[sr][sc] = newColor;
            if (sr >= 1) nj(image, sr-1, sc, color, newColor);
            if (sc >= 1) nj(image, sr, sc-1, color, newColor);
            if (sr+1 < image.size()) nj(image, sr+1, sc, color, newColor);
            if (sc+1 < image[0].size()) nj(image, sr, sc+1, color, newColor);
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int color = image[sr][sc];
        if(color != newColor) nj(image,sr,sc,color,newColor);
        return image;
    }
};