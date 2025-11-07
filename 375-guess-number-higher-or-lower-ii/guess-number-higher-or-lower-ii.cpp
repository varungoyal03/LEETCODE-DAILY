class Solution {
public:
  vector<vector<int>> t;
int solve(int l,int r){
    if (l>=r) return 0;

    if(t[l][r]!=-1 ) return t[l][r];

int ans=INT_MAX;
    for(int i=l;i<=r;i++){
        int maxCost=max(solve(l,i-1),solve(i+1,r));
        ans=min(ans, i+maxCost);
    }
    return t[l][r]=ans;
}
    int getMoneyAmount(int n) {
   //you choose  min , appononetn max(higher or lower) opponent always say you guessed wrong
 t.assign(n + 1, vector<int>(n + 1, -1));
   return  solve(1,n);
    }
};

