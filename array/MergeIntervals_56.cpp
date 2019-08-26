/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


WrittenBy : Himanshu Srivastava
Problem : Merge Intervals
TimeComplexity : O(n)

*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        if( n < 1){
            return intervals;
        }

        vector<vector<int>> res;
        sort( intervals.begin(), intervals.end(),[](vector<int> a, vector<int> b){ return a[0] < b[0] ;});

        res.push_back(intervals[0]);

        for( int i = 1 ; i < n ; i++){

            if( res.back()[1] < intervals[i][0]){ res.push_back(intervals[i]);}
            else
                res.back()[1] = max(res.back()[1],intervals[i][1]);
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
    int maxSum = sol.merge(input);
    cout<<maxSum<<endl;

    return 0;
}
