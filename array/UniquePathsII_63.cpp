/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

WrittenBy : Himanshu Srivastava
Problem : Unique Paths II
TimeComplexity : O(m*n)

*/

#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0) );

        dp[0][1] =1;

        for( int i = 1; i <= m ; i++)
            for(int j = 1; j <= n; j++){
                if( !obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }

        return dp[m][n];

    }
};



void displayInt(vector<int>input){
    cout<<"Displaying size "<<input.size()<<endl;
    for (std::vector<int>::size_type i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main(){

    Solution sol;

    vector<vector<int>> obstacleGrid = {
  {0,0,0},
  {0,1,0},
  {0,0,0}
  };
    int path = sol.uniquePathsWithObstacles(obstacleGrid);
    cout<<path<<endl;

    return 0;
}
