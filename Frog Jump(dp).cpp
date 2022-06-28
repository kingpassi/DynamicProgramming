/******************************************************************************
Frog Jump

Problem Statement
There is a frog on the 1st step of an N stairs long staircase. 
The frog wants to reach the Nth stair. HEIGHT[i] is the height of 
the (i+1)th stair.If Frog jumps from ith to jth stair, the energy 
lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog 
is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. 
Your task is to find the minimum total energy used by the frog to reach from
1st stair to Nth stair.

Sample Input 1:
2
4

10 20 30 10
3
10 50 10
Sample Output 1:
20
0
Explanation Of Sample Input 1:
For the first test case,
The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
So, the total energy lost is 20 which is the minimum. 
Hence, the answer is 20.

For the second test case:
The frog can jump from 1st stair to 3rd stair (|10-10| = 0 energy lost).
So, the total energy lost is 0 which is the minimum. 
Hence, the answer is 0.
Sample Input 2:
2
8
7 4 4 2 6 6 3 4 
6
4 8 3 10 4 4 
Sample Output 2:
7
2


*******************************************************************************/

#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int jumpTwo=INT_MAX;
        int jumpOne=prev+abs(heights[i]-heights[i-1]);
        if(i>1)
            jumpTwo=prev2+abs(heights[i]-heights[i-2]);
        int curr=min(jumpOne,jumpTwo);
        prev2=prev;
        prev=curr;
        
    }
    return prev;
}