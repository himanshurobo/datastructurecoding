/*

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.


WrittenBy : Himanshu Srivastava
Problem : Max Area of Island
TimeComplexity : O(n)

*/


class Solution {
    
    int maxAreaOfIsland(vector<vector<int>>& grid,int x, int y) {
        
        if( x < 0  || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1){
            return 0;
        }
        
        
        grid[x][y] = 0;
        
        
        return maxAreaOfIsland( grid,x+1,y) + maxAreaOfIsland( grid, x, y+1 ) + maxAreaOfIsland( grid, x-1, y )  + maxAreaOfIsland( grid, x, y-1 ) + 1;
        
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int sum = 0 ;
        int maxSum = 0 ;
        for( int i = 0 ; i < m;i++){
            for( int j =0 ; j < n ; j++){
                
                if( grid[i][j] == 1){
                    sum = maxAreaOfIsland( grid, i, j);
                    
                    maxSum = std::max(maxSum,sum);
                }
            }
        }
        
        return maxSum;
        
    }
};