/******************************************************************************
931. Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum sum of any
falling path through matrix.

A falling path starts at any element in the first row and chooses the 
element in the next row that is either directly below or diagonally left/right.
Specifically, the next element from position (row, col) will be
(row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59

*******************************************************************************/
class Solution {
public:
    int f(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        
        if(j<0 ||j>=matrix[0].size()) return 1e9;
        if(i==0) return matrix[i][j] ;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int u= matrix[i][j]+f(i-1,j,matrix,dp);
        int l=matrix[i][j]+f(i-1,j-1,matrix,dp);
        int r=matrix[i][j]+f(i-1,j+1,matrix,dp);
        
      return dp[i][j]= min(u,min(l,r));
        
    }
        
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int  n=matrix.size();
      int  m=matrix[0].size();
      vector<vector<int>>dp(n,vector<int>(m,-1));
        
        int mini=1e9;
        for(int j=0;j<m;j++){
            mini=min(mini,f(n-1,j,matrix,dp));
            
        }
        
        return mini;
        
        
    }
};



/*
//tabulation
class Solution {
public:
   
        
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int  n=matrix.size();
      int  m=matrix[0].size();
      vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++) dp[0][j]=matrix[0][j];
        
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                
        int u= matrix[i][j]+dp[i-1][j];
                
        int l=matrix[i][j];
            if(j-1>=0) l+=dp[i-1][j-1];
            else l+= 1e9;
                
        int r=matrix[i][j];
            if(j+1<m) r+=dp[i-1][j+1];
             else r+= 1e9;
                
            dp[i][j]=min(u,min(l,r));       
                
            }
        }
            
            
        int mini=1e9;
        for(int j=0;j<m;j++){
            mini=min(mini,dp[n-1][j]);
            
        }
        
        return mini;
        
        
    }
};
*/

/*

//optimized
 class Solution {
public:
   
        
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int  n=matrix.size();
      int  m=matrix[0].size();
      vector<int>prev(m,0), curr(m,0);
        
        for(int j=0;j<m;j++) prev[j]=matrix[0][j];
        
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                
        int u= matrix[i][j]+prev[j];
                
        int l=matrix[i][j];
            if(j-1>=0) l+=prev[j-1];
            else l+= 1e9;
                
        int r=matrix[i][j];
            if(j+1<m) r+=prev[j+1];
             else r+= 1e9;
                
           curr[j]=min(u,min(l,r));       
                
            }
            
            prev=curr;
        }
            
            
        int mini=1e9;
        for(int j=0;j<m;j++){
            mini=min(mini,prev[j]);
            
        }
        
        return mini;
        
        
    }
}; 
 */