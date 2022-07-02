/*0 1 Knapsack
Problem Statement
A thief is robbing a store and can carry a maximal weight of W into
his knapsack. There are N items and the ith item weighs wi and is 
of value vi. Considering the constraints of the maximum weight that 
a knapsack can carry, you have to find and return the maximum value 
that a thief can generate by stealing items.
Input Format:
The first line contains a single integer T representing the number of 
test cases.      
The T-test cases are as follows:

Line 1:The first line contains an integer, that denotes the value of N. 
Line 2:The following line contains N space-separated integers, that denote
the values of the weight of items. 
Line 3:The following line contains N space-separated integers, that denote 
the values associated with the items. 
Line 4:The following line contains an integer that denotes the value of W.
W denotes the maximum weight that a thief can carry.
Output Format :
The first and only line of output contains the maximum value that a thief
can generate, as described in the task. 
The output of every test case is printed in a separate line.

Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13
*******************************************************************************/
int knapsack(vector<int>wt,vector<int>val, int n ,int maxWeight){
    

vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
for(int W=wt[0];W<=maxWeight;W++) dp[0][W]=val[0];

for(int ind=1;ind<n;ind++){
    for(int W=0;W<=maxWeight;W++){
        int notTake=0+dp[ind-1][W];
        int take=INT_MIN;
        if(wt[ind]<=W){
            take=val[ind]+dp[ind-1][W-wt[ind]];
            
        }
        dp[ind][W]=max(take,notTake);
    }
}
return dp[n-1][maxWeight];
}
