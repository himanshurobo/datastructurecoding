/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

WrittenBy : Himanshu Srivastava
Problem : Triangle
TimeComplexity : O(n)

*/



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        // MaxRow same as MaxColumn
        int maxRow = triangle.size();

        vector<int> dp = triangle[triangle.size()-1];

        //Bottom Up Approach
        for( int row = maxRow-2 ; row >=0 ; row--){
            for( int col = 0; col < triangle[row].size(); col++){
                    dp[col] = triangle[row][col] + min( dp[col],dp[col+1]);
                }
            }

        return dp[0];
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

    int numRows = 5;

    displayInt(sol.minimumTotal(numRows));

    return 0;
}
