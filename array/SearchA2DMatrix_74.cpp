/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

WrittenBy : Himanshu Srivastava
Problem : Search a 2D Matrix
TimeComplexity : O(m*n)

*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if( matrix.size() == 0 ){
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int matSize = m*n;

        int start = 0 ;
        int end = matSize-1;


        while( start <= end ){

            int mid = start + (end-start)/2;

            int row = mid/n;
            int col = mid%n;

            if( matrix[row][col] == target){
                return true;
            }

            if( matrix[row][col] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }

        }

        return false;

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
