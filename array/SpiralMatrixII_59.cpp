/*

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]


WrittenBy : Himanshu Srivastava
Problem : Spiral Matrix II
TimeComplexity : O(n)

*/

#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int> > res( n, vector<int>(n) );

        int rowBegin = 0;
        int rowEnd = n-1;
        int colBegin = 0 ;
        int colEnd = n-1;
        int count = 1;

        while( rowBegin <= rowEnd && colBegin <= colEnd ){

            for( int col = colBegin; col <= colEnd;  col++){
                res[rowBegin][col] = count++;
            }

            rowBegin++;

            for( int row = rowBegin; row <= rowEnd; row++){
                res[row][colEnd] = count++;
            }

            colEnd--;


            for( int col = colEnd; col >= colBegin; col--){
                res[rowEnd][col] = count++;
            }


            rowEnd--;


            for( int row = rowEnd; row >= rowBegin; row--){
                res[row][colBegin] = count++;
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

    int n = 5
    sol.generateMatrix(n);


    return 0;
}
