class Solution {
public:
using pp=pair<int,int>;
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        unordered_map<int,int> freq;

        set<pp,greater<pp> > s;//FREQ,EEMETS

        for(int i=0;i<k;i++){
            freq[nums[i]]++;
        }

        for(auto &p:freq) s.insert({p.second,p.first});

int sum=0;
        int count=0;
        for(auto &it:s){
                sum+=it.first*it.second;
                count++;
                if(count==x) break;
        }

ans.push_back(sum);


        for(int i=k;i<nums.size();i++){
            int old=nums[i-k];
            s.erase({freq[ old ],old});
            freq[old]--;
           if(freq[old]) s.insert({freq[ old ],old});


            int newi=nums[i];
            s.erase({freq[ newi ] ,newi});
            freq[newi]++;
            s.insert({freq[ newi ],newi});



         int sum=0;
        int count=0;
        for(auto it:s){
                sum+=it.first*it.second;
                count++;
                if(count==x) break;
        }

ans.push_back(sum);
           
        }





        
  return ans;  }
};