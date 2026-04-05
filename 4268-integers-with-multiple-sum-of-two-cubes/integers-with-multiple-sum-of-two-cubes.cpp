class Solution {
public:
    vector<int> findGoodIntegers(int n) {

        map<int,int> mp;

        for(int i=0;i<1000;i++){
            for(int j=i;j<1000;j++){//j=i

                int sum=i*i*i+j*j*j;
                if (sum > n) break;  // 🔥 pruning WITHOUT IT TLE
                mp[sum]++;
            }
        }

        vector<int> ans;
        for(auto &x:mp){
            if(x.first>n) break;
            if(x.second>1) ans.push_back(x.first);
        }

        return ans;



    }
};