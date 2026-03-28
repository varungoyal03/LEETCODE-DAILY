class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();

        k=k%n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                int finalIdx;

                if(i&1){//odd->shift right
                      finalIdx=(j-k+n)%n;  
                         
                }
                else{
                        finalIdx=(j+k)%n; 
                }

                if(mat[i][j]!=mat[i][finalIdx]) return false;
            }
        }
   return true; }
};