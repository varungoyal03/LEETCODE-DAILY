class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=1e5+5;

        vector<bool> isPrime(n+1,1);
        isPrime[0]=isPrime[1]=0;//
        
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=0;

                }
            }

        }

        set<int> primes;
        for(int i=2;i<=n;i++){
            if(isPrime[i]) primes.insert(i); 
        }

int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i&1){
                while(isPrime[nums[i]]) {
                    nums[i]++;
                    ans++;
                }

            }
            else{

                ans+= (*primes.lower_bound(nums[i]))-nums[i];
            }
        }

        return ans;
    }
};