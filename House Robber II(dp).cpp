/******************************************************************************
House Robber II

Problem Statement
Mr. X is a professional robber planning to rob houses along a street.
Each house has a certain amount of money hidden. All houses along this 
street are arranged in a circle. That means the first house is the neighbor
of the last one. Meanwhile, adjacent houses have a security system connected,
and it will automatically contact the police if two adjacent houses were broken
into on the same night.

You are given an array/list of non-negative integers 'ARR' representing the
amount of money of each house. Your task is to return the maximum amount of 
money Mr. X can rob tonight without alerting the police.

Input Format :
The first line of input contains an integer 'T' representing the number of 
the test case. Then the test case follows.

The first line of each test case contains an integer, ‘N’ representing the 
size of the first array/list.

The second line of each test case contains 'N' single space-separated integers
representing the array/list elements.
Output Format :
For each test case, print a single line containing a single integer denoting
the maximum money that can be robbed in a separate line.

The output of each test case will be printed in a separate line.

Sample Input 1:
3
1
0
3
2 3 2
4
1 3 2 1
Sample Output 1:
0
3
4
*******************************************************************************/
//Space Optimization
 long long int f(vector<int> &nums){
   long long int n=nums.size();
   long long int prev=nums[0];
   long long int prev2=0;
    for(int i=1;i<n;i++){
       long long int pick=nums[i];
        if(n>1){
            pick+=prev2;
        }
       long long int notpick=0+prev;
       long long int curr=max(pick,notpick);
        prev2=prev;
        prev=curr;
        
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
   vector<int>temp1,temp2;
   long long int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(f(temp1),f(temp2));
}
