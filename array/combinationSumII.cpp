/*

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]


WrittenBy : Himanshu Srivastava
Problem : Combination Sum II
TimeComplexity : O(2^n)

*/


#include<iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


class Solution {

     private :

    void dfs( vector<int>& candidates, int target, int index, vector<int>path,vector<vector<int>>& res){

        if( target == 0){
            res.push_back(path);
            return;
        }

        for( int i = index; i < candidates.size();i++){

            if( candidates[i] > target ){
                return;
            }

            if( i > index && candidates[i] == candidates[i-1]){
                continue;
            }

            path.push_back(candidates[i]);

            dfs(candidates,target-candidates[i],i+1,path,res);

            path.pop_back();


        }

    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, path,res);
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

    vector<int> input{10,1,2,7,6,1,5};
    int target = 8
    vector<vector<int>> res;
    res = sol.combinationSum2(input,target);
    displayInt(res);

    return 0;
}
