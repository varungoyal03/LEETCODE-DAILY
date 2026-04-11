class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        int maxn=1<<n;

      vector<bool> mp(maxn, 0);

        for(auto &s:nums)
        {
            int num=stoi(s,0,2);
            mp[num]=1;
        }

        for(int i=0;i<maxn;i++){
            if(!mp[i]) {
                string s=bitset<32>(i).to_string();
                return s.substr(32-n);
            }

        }
    return "0";}
};