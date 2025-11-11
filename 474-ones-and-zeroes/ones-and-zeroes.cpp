class Solution {
public:
    int count(int i, int m, int n,vector<string>& strs){
        if(i==strs.size() ) return 0;

            string s=strs[i];
            int zeros = ranges::count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;
            
            int include=0;
            if(m-zeros>=0 && n-ones>=0)
            include=1+count(i+1,m-zeros,n-ones,strs);

            int exclude=count(i+1,m,n,strs);

            return max(include,exclude);

       
    }
    int findMaxForm(vector<string>& strs, int M, int N) {
        int size=strs.size();
        // return count(0,M,N,strs);
        vector<vector<int>> curr(M+1,vector<int>(N+1,0));
          vector<vector<int>> ahead(M+1,vector<int>(N+1,0));

        for(int i=size-1;i>=0;i--){
            for(int m=0;m<=M;m++){
                for(int n=0;n<=N;n++){


            string s=strs[i];
            int zeros = ranges::count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;
            
            int include=0;
            if(m-zeros>=0 && n-ones>=0)
            include=1+ahead[m-zeros][n-ones];

            int exclude=ahead[m][n];

             curr[m][n]= max(include,exclude);}


                }
                  ahead=curr;
            }

       
    
return ahead[M][N];
    }
};