class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
int maxfreq=0;
        for(int x:nums) {mp[x]++;
        maxfreq=max(maxfreq,mp[x]);}
int count=0;
        for(auto &p:mp){
            if(p.second==maxfreq){
                count++;
            }
        }


return count* maxfreq;
    }
};