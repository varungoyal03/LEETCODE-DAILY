class Solution {
public:
    bool isTrionic(vector<int>& a) {
        int n=a.size();

vector<int> changes;
int val=0;

        for(int i=1;i<n;i++){
            if (a[i-1]<a[i]) val=1;
            else if (a[i-1] > a[i]) val=-1;
            else val=0;

            if(changes.empty() || changes.back() !=val ) changes.push_back(val);
        }

        vector<int> target ={1,-1,1};

        return changes==target;
    }
};