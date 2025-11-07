class Solution {
public:
 vector<vector<int>>  dp;
    int solve(string &s1, string &s2,int i,int j){
        if(i==s1.size()){
            return s2.size()-j;
        }
        if(j==s2.size()){
            return s1.size()-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        if(s1[i]==s2[j]) ans=solve(s1,s2,i+1,j+1);

        else{//I D R
            ans=1+ min({ solve(s1,s2,i,j+1), 
                            solve(s1,s2,i+1,j), 
                            solve(s1,s2,i+1,j+1)
            });
        }
return dp[i][j]= ans;
    }


    int minDistance(string s1, string s2) {
        dp.assign(s1.size()+1, vector<int>(s2.size()+1,-1));


    //   return  solve(s1,s2,0,0);
    for(int j=0;j<=s2.length();j++ ){
            dp[s1.size()][j]=s2.size()-j;
        }

           for(int i=0;i<=s1.length();i++ ){
            dp[i][s2.size()]=s1.size()-i;
        }


     

        for(int i=s1.length()-1;i>=0;i--){
            for(int j=s2.length()-1;j>=0;j--){
                    int ans=0;
                    if(s1[i]==s2[j]) ans=dp[i+1][j+1];

                    else{//I D R
                        ans=1+ min({ dp[i][j+1], 
                                        dp[i+1][j], 
                                        dp[i+1][j+1]
                        });
                            
                    }
                   dp[i][j]= ans;

            }}
        







  return dp[0][0];  }


};