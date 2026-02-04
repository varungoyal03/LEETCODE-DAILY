class Solution {
        using ll = long long;
public:
    int minTime(string strin, vector<int>& order, int k) {
       int n=strin.size();

       ll cnt=0;

       set<int> s={-1,n};

       for(int i=0;i<order.size();i++){
        int pos=order[i];

        auto prev=--s.lower_bound(pos);
        auto next=s.upper_bound(pos);


        ll before=pos- int(*prev);
        ll after=int(*next) -pos;

        cnt+=before*after;
        if(cnt>=k) return i;
         
         s.insert(pos);


       }

return -1;
    }
};