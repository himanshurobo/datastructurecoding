/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.


WrittenBy : Himanshu Srivastava
Problem : First Missing Positive
TimeComplexity : O(n)

*/

#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();

        for(int i = 0; i < n; ++ i){
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i]){
                // cout<<i<<" "<<A[A[i] - 1]<<"<-->"<<A[i]<<endl;
                swap(A[i], A[A[i] - 1]);

            }
    
        }

                                       for(int i = 0; i < n; ++ i){
                    cout<<A[i]<<" ";
                }

        for(int i = 0; i < n; ++ i){

            if(A[i] != i + 1)
                return i + 1;
        }
        return n + 1;

    }

int firstMissingPositive1(vector<int>& A) { 

    int numSize = A.size();
    // int i =0;
    for ( int i = 0 ; i < numSize; i++){
        int index = abs(A[i]) - 1;
        cout<<index<<" "<<A[index]<<" "<<A[i]<<endl;
        A[index] = A[index] > 0 ? -A[index] : A[index];
        // cout<<A[index]<<" ";
    }

    for ( int i = 0 ; i < numSize ; i++){
        
        if ( A[i] > 0){
            return i+1;
        }
    }

    return -1;

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

    vector<int> input{3,4,-1,1};
    vector<vector<int>> res;
    int missing = sol.firstMissingPositive(input);
    cout<<"Missing -->"<<missing<<endl;

    return 0;
}
