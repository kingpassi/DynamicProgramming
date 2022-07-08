/******************************************************************************
983. Minimum Cost For Tickets

You have planned some train traveling one year in advance. The days
of the year in which you will travel are given as an integer array days.
Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 
7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the
given list of days.

 

Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you
travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days
3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel
your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered 
days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
*******************************************************************************/
//tabulation

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,INT_MAX);
        dp[n]=0;
        for(int k=n-1;k>=0;k--){
            
            int option1= costs[0]+ dp[k+1];
            int i;
            
            for(i=k; i<n && days[i]<days[k]+7;i++);
            int option2=costs[1]+dp[i];
             
            for(i=k;i<n && days[i]<days[k]+30;i++);
            int option3=costs[2]+dp[i];
            
            dp[k]=min(option1,min(option2,option3));
        }
        return dp[0];
    }
};

//memoization
/*
class Solution {
public:
    int f(int n, vector<int>& days, vector<int>& costs, int index,vector<int>&dp){
        if(index>=n) return 0;
        
        if(dp[index]!=-1) return dp[index];
        int option1=costs[0]+f(n,days,costs,index+1,dp);
        
        int i;
        for(i=index;i<n && days[i]<days[index]+7;i++);
        int option2=costs[1]+f(n,days,costs,i,dp);
         
        for(i=index;i<n && days[i]<days[index]+30;i++);
        int option3=costs[2]+f(n,days,costs,i,dp);
        
        return dp[index]= min(option1,min(option2,option3));
    }
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
       return f(n,days,costs,0,dp);
    }
};*/