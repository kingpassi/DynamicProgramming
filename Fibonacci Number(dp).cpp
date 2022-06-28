/******************************************************************************
509. Fibonacci Number
The Fibonacci numbers, commonly denoted F(n) form a sequence, 
called the Fibonacci sequence, such that each number is the sum of the
two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
*******************************************************************************/
//optimized time (o(n)) and space complexity(o(1))
class Solution {
public:
    int fib(int n) {
       
      int  prev2=0;
      int  prev=1;
        if(n<=1) return n;
        
        for(int i=2;i<=n;i++){
            int curr =prev2+prev;
            prev2=prev;
            prev=curr;

        }
        return prev;
    }
};



/* 
//Memorization code

#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int>& dp){
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n];
    return dp[n]= f(n-1,dp) + f(n-2,dp);
}


int main() {

  int n=5;
  vector<int> dp(n+1,-1);
  cout<<f(n,dp);
  return 0;
}

*/
/*
//Tabulation code
#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=5;
  vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}
*/