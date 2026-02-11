class Solution {
public:
        map<string,vector<char>>mp;
        map<string,bool> dp;

    bool can(int i,string c,string b){
        if(b.size()==1) return true;
        if(i==b.size()-1){
            if(dp.count(c)) return dp[c];
            return dp[c]=can(0,"",c);
        }
        string k=b.substr(i,2);
        if(!mp.count(k)) return false;                      

        for(char ch:mp[k]){
            if(can(i+1,c+ch,b)) return true;
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {

        for(string &s:allowed) mp[s.substr(0,2)].push_back(s[2]);

        return can(0,"",bottom);
    }
};