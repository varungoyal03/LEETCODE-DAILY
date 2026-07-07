class Solution {
public:
vector<vector<int>> ans;
vector<int> temp;
int K;

void solve(int  currNum,int sum){
    //BASE CASE 1: Perfect Match!
    if(sum==0 && temp.size()==K) return ans.push_back(temp);

// 2. Failure  Base Cases
    if(currNum>9 || sum<0 || temp.size()>K ) return ;

   // 3. Mathematical Impossibility Prune(optional)
   int elementsNeeded = K - temp.size();
        int elementsAvailable = 9 - currNum + 1;
        if (elementsNeeded > elementsAvailable) return;

       

    solve(currNum+1,sum);//not take

temp.push_back(currNum);
    solve(currNum+1,sum-currNum);//take
    temp.pop_back();

}
    vector<vector<int>> combinationSum3(int k, int n) {
        K=k;//
      

      solve(1,n) ;
      return ans;
    }
};