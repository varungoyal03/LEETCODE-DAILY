class Solution {
public:

    vector<pair<int,int>> direction={{1,0} ,{-1,0},{0,1},{0,-1} };

    int m;
    int n;
    
     void dfs(int r, int c, int oldColor, int newColor, vector<vector<int>>& image) {
            if (r < 0 || c < 0 || r >= m || c >= n  || image[r][c] != oldColor ) return;

        image[r][c]=newColor;
        for(auto &[x,y]:direction){
            dfs(r+x,c+y,oldColor,newColor,image);
        }

     }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     m = image.size();
     n = image[0].size();
    int newColor=color;
    int oldColor=image[sr][sc];

        if (oldColor == newColor) return image;

        dfs(sr,sc,oldColor,newColor,image);
        return image;
    }
};

//VISITED OLD COLOR CELL ;> CHANGE TO NEW COLOR