/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


WrittenBy : Himanshu Srivastava
Problem : Insert Interval
TimeComplexity : O(n)

*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {


        vector<vector<int>> res;

        int n = intervals.size();
        int curr = 0;

        while(curr < n && intervals[curr][1] < newInterval[0]  ){
            res.push_back(intervals[curr++]);
        }


        while( curr < n && intervals[curr][0] <= newInterval[1]){
            newInterval[0] = min( intervals[curr][0], newInterval[0]);
            newInterval[1] = max( intervals[curr][1], newInterval[1]);
            curr++;
        }

        res.push_back(newInterval);

        while( curr < n)
            res.push_back(intervals[curr++]);

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
    int maxSum = sol.insert(input);
    cout<<maxSum<<endl;

    return 0;
}
