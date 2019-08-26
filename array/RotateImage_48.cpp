/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]


WrittenBy : Himanshu Srivastava
Problem : Rotate Image
TimeComplexity : O(n*n)

*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        for( int i = 0 ; i < matrix.size();i++){
            for( int j = 0; j < i; j++){
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for( int i = 0 ; i < matrix.size();i++){

            reverse(matrix[i].begin(),matrix[i].end());
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

    vector<vector<int>>input{2,3,1,1,4};
    vector<vector<int>> res;
    int jump = sol.rotate(input);
    cout<<jump<<endl;

    return 0;
}
