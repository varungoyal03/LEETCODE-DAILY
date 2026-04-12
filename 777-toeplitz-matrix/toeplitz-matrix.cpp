class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        map<int,int> mp;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int key=i-j;
                
                if(!mp.count(key)) mp[key]=matrix[i][j];
                else if(mp[key]!=matrix[i][j]) return false;
            }
        }
        
    return true; }
};