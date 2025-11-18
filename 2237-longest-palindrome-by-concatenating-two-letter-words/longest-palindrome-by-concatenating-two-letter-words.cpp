class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        vector<vector<int>> mp(26,vector<int>(26,0));

        for(auto w:words){
            int i=w[0]-'a';
            int j=w[1]-'a';
            mp[i][j] ++;
         }  


        int len=0;
        bool hasDouble=false;
         for(int i=0;i<26;i++){
            if(mp[i][i] & 1){
                hasDouble=true;
                len+=(mp[i][i]-1)*2;//
            }
            else{
                 len+=mp[i][i]*2;
            }
         }
         len+=hasDouble*2;

         for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){

              int pairs=min(  mp[i][j],mp[j][i] );
              len+=pairs*4;//
            }
         }
    return len;}
};