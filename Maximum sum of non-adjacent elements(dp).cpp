/******************************************************************************
Maximum sum of non-adjacent elements

Problem Statement
You are given an array/list of ‘N’ integers. You are supposed to return 
the maximum sum of the subsequence with the constraint that no two elements
are adjacent in the given array/list.

Input Format:
The first line contains a single integer ‘T’ denoting the number of test cases.

The first line of each test case contains a single integer ‘N’ 
denoting the number of elements in the array.

The second line contains ‘N’ single space-separated integers denoting 
the elements of the array/list.


Output Format:
For each test case, print a single integer that denotes the maximum sum 
of the non-adjacent elements.

Print the output of each test case in a separate line.

Sample Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11
*******************************************************************************/
//Space Optimization
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
   int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(n>1){
            pick+=prev2;
        }
        int notpick=0+prev;
        int curr=max(pick,notpick);
        prev2=prev;
        prev=curr;
        
    }
    return prev;
}

/*
//memoization
#include <bits/stdc++.h>

using namespace std;

int solveUtil(int ind, vector<int>& arr, vector<int>& dp){
    
    if(dp[ind]!=-1) return dp[ind];
    
    if(ind==0) return arr[ind];
    if(ind<0)  return 0;
    
    int pick= arr[ind]+ solveUtil(ind-2, arr,dp);
    int nonPick = 0 + solveUtil(ind-1, arr, dp);
    
    return dp[ind]=max(pick, nonPick);
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return solveUtil(n-1, arr, dp);
}


int main() {

  vector<int> arr{2,1,4,9};
  int n=arr.size();
  cout<<solve(n,arr);

}


*/


/*
//Tabulation approach
#include <bits/stdc++.h>

using namespace std;

int solveUtil(int n, vector<int>& arr, vector<int>& dp){
    
    dp[0]= arr[0];
    
    for(int i=1 ;i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }
    
    
    return dp[n-1];
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return solveUtil(n, arr, dp);
}


int main() {

  vector<int> arr{2,1,4,9};
  int n=arr.size();
  cout<<solve(n,arr);

}
*/
