class Solution {
public:
    int recursive(int amount , int n , vector<int>& coins){
        
        if(n==0)
            return (amount == 0);
        if(amount == 0)
            return 1;
        
        if(coins[n-1] <= amount )
             return recursive(amount-coins[n-1] , n , coins) + recursive(amount , n-1,coins);
        else
            return recursive(amount , n-1 ,coins);
    }
    
    int iterative(int amount , int n , vector<int>& coins){
        int dp[n+1][amount+1];
        
        for(int i=0;i<=amount;i++)
            dp[0][i] = 0;
        for(int i =0;i<=n;i++)
            dp[i][0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1] <=j)
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount];
        
        
    }
    int change(int amount, vector<int>& coins) {

        // return recursive(amount , coins.size() , coins);
        return iterative(amount , coins.size() , coins);

    }
};