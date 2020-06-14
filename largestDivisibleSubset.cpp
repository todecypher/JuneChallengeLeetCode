class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n = nums.size();
       vector<int>res , parent(n); 
       sort(nums.begin() , nums.end());
      
       vector<int> mp(n);
       vector<vector<int>>v(n);
      
         int ans = 0;
         int maxi =0  ;
       for(int i=n-1;i>=0;i--){
           for(int j=i; j<n;j++){
               if(nums[j] % nums[i] ==0){
                   if(mp[i] < 1+mp[j]){
                       mp[i] = 1+ mp[j];
                       parent[i] = j;
                   }
                   
               }
           }
           if(ans < mp[i]){
               ans = mp[i];
               maxi = i;
           }
       }
       
       while(ans--){
           res.push_back(nums[maxi]);
           maxi = parent[maxi];
       }
        return res;
    }
     
};