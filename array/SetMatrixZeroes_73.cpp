/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

WrittenBy : Himanshu Srivastava
Problem : Set Matrix Zeroes
TimeComplexity : O(m*n)

*/

#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector<bool> row_zero(matrix.size(),false);
        vector<bool> col_zero(matrix[0].size(),false);
        int i, j;
        for (i=0;i<row_zero.size();i++) {
            for (j=0;j<col_zero.size();j++) {
                if (matrix[i][j]==0) {
                    row_zero[i]=true;
                    col_zero[j]=true;
                }
            }
        }
        for (i=0;i<row_zero.size();i++) {
            for (j=0;j<col_zero.size();j++) {
                if (row_zero[i]) matrix[i][j]=0;
                else if (col_zero[j]) matrix[i][j]=0;
            }
        }

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

    vector<vector<int>> matrix;

    sol.setZeroes(matrix);

    return 0;
}
