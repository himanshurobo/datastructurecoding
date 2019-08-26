/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


WrittenBy : Himanshu Srivastava
Problem : Spiral Matrix
TimeComplexity : O(n*m)

*/



#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {


        vector<int> res;
        if( !matrix.size() ){
            return res;
        }

        int rowBegin = 0;
        int rowEnd = matrix.size()-1;
        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;



        while( rowBegin <= rowEnd && colBegin <= colEnd){

            for( int col = colBegin; col <= colEnd; col++){
                res.push_back(matrix[rowBegin][col]);
            }

            rowBegin++;

            for( int row = rowBegin; row <= rowEnd;row++){
                res.push_back(matrix[row][colEnd]);
            }

            colEnd--;


            if( rowBegin <= rowEnd){
                for( int col = colEnd; col >= colBegin;col--){
                    res.push_back(matrix[rowEnd][col]);
                }
            }

            rowEnd--;


            if( colBegin <= colEnd ){
                for( int row = rowEnd; row >= rowBegin; row--){

                    res.push_back(matrix[row][colBegin]);
                }
            }

            colBegin++;
        }

        return res;
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

    vector<int> input{-2,1,-3,4,-1,2,1,-5,4};
    int maxSum = sol.spiralOrder(input);
    cout<<maxSum<<endl;

    return 0;
}
