/*

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
 find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]



WrittenBy : Himanshu Srivastava
Problem : Combination Sum I
TimeComplexity : O(logn)



*/




#include"../header.hpp"



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

            path.push_back(candidates[i]);

            dfs(candidates,target-candidates[i],i,path,res);

            path.pop_back();


        }

    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

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

    vector<int> input{2,3,6,7};
    int target = 8;
    vector<vector<int>> res;
    res = sol.combinationSum(input,target);
    displayInt(res);

    return 0;
}
