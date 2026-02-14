class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> t(101,vector<double>(101,0.0));

        t[0][0]=poured;

        for(int r=0;r<=query_row;r++){
            for(int c=0;c<r+1;c++){
                if(t[r][c]<=1) continue;

                double extra=(t[r][c]-1)/2.0;

                t[r][c]=1;//
                t[r+1][c]+=extra;
                t[r+1][c+1]+=extra;
            }
        }

    return t[query_row][query_glass];}
};