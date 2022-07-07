/******************************************************************************
322. Coin Change

You are given an integer array coins representing coins of different 
denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins,
return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0
*******************************************************************************/
class Solution {
    public:
    
    int f(vector<int>& coins, int amount, int n,  vector<vector<int>>&dp){
        
        if(n==0) return INT_MAX-1;
        if(amount==0) return 0;
        if(amount<0) return INT_MAX-1;
        if(dp[n][amount]!=-1) return dp[n][amount];
        return dp[n][amount]=min(f(coins,amount,n-1,dp),1+f(coins,amount-coins[n-1],n,dp));
        
    }
    
    

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
       int ans=f(coins,amount,coins.size(),dp);
        if(ans==INT_MAX-1) return -1;
        else return ans;
        
    }
};