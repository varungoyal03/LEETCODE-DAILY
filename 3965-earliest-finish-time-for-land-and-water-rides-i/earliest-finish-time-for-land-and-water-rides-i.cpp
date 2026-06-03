class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        
int n=ld.size();
int m=wd.size();
        int ans=1e9;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                    int enda=ls[i]+ld[i];
                    int endb=ws[j]+wd[j];

                    int ltow=max(enda+wd[j],endb);

                    int wtol=max(endb+ld[i],enda);

                    ans=min({ans,ltow,wtol});


            }

        }

        return ans;
    }
};