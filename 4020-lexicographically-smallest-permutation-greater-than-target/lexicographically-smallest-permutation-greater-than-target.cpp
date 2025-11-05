class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        int n=s.size();
        multiset<char> chs;
        for(auto &ch:s) chs.insert(ch);

        string ans="";

        string pref="";

        for(int i=0;i<n;i++){
            auto gt=chs.upper_bound(t[i]);
            if(gt!=chs.end()){
                char gtVal=*gt;

                string temp=pref;
                temp.push_back(gtVal);
                chs.erase(gt);

                for(char x:chs) temp.push_back(x);
                chs.insert(gtVal);
                if (ans!="")  ans=min(ans,temp);
                else ans=temp;

            }
        auto curr=chs.find(t[i]);
        if(curr==chs.end()) break;

            pref.push_back(t[i]);
            chs.erase(curr);
        }
   return ans; }
};