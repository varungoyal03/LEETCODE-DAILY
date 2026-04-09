class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        vector<int> mp(26,0);

        for(auto &w:words){
            for(auto &ch:w){
                mp[ch-'a']++;
            }
        }

        for(int i=0;i<26;i++){
            if(mp[i] && mp[i]%n!=0) return false;
        }

        return true;
    }
};