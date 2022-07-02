/*64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right, which minimizes the sum of
all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*******************************************************************************/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows==0) return 0;   
        int cols = grid[0].size();
        
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        int i,j;   
        dp[0][0] = grid[0][0]; 
        
        for(i=1;i<cols;++i)
            dp[0][i] = dp[0][i-1] + grid[0][i];
       
        for(i=1;i<rows;++i)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        
        for(i=1;i<rows;++i)
        {
            for(j=1;j<cols;++j)
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
        return dp[rows-1][cols-1];
    }
};