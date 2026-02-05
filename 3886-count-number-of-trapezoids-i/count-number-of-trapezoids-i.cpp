class Solution {
    using ll=long long;
public:

    const int M = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        ll ans =0;

        map<int,int> mp;
        for(auto i: points){
            mp[i[1]]++;
        }

        ll edgesSum =0;
//FOR EACH TOP SEE NO, OF BOTTOM 
        for(auto i: mp ){

            ll edges = (i.second*1LL*(i.second-1))/2;

            ans = (ans + edges*edgesSum)% M;
            edgesSum+=edges;
        }

        return ans;
    }
};

