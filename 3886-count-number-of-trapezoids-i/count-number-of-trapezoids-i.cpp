
using ll = long long;
const int M = 1e9 +7;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {

    

       unordered_map<int,int> mp;
        for(auto i: points){
            mp[i[1]]++;
        }
        ll edgesSum =0;
        ll cnt_of_same_line=0;

        for(auto i: mp ){
 
            ll edges = (i.second*1LL*(i.second-1))/2;
            cnt_of_same_line += edges*(edges-1)/2;

            
            edgesSum+=edges;
        }

        edgesSum%=M;
        ll total_ways = edgesSum*(edgesSum-1)/2; 
        total_ways%=M;
        cnt_of_same_line%=M;

        ll ans=(total_ways-cnt_of_same_line+M)%M;
        return ans;
    }
};